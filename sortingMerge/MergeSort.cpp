#include <iostream>
#include<string>
#include<climits>
using namespace std;

void PrintArray(int *array, int n) {
	for (int i = 0; i < n; ++i)
		cout << array[i] << " " << flush;
	cout << endl;
}

void Merger(int arr[], int lo, int  mi, int hi) {
	int *temp = new int[hi - lo + 1];
	int i = lo, j = mi + 1;
	int k = 0;
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mi)
		temp[k++] = arr[i++];

	while (j <= hi)
		temp[k++] = arr[j++];

	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;
}
void MergeSortHelper(int arr[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSortHelper(arr, lo, mid);
		MergeSortHelper(arr, mid + 1, hi);
		Merger(arr, lo, mid, hi);
	}
}
void MergeSort(int arr[], int arr_size) {
	MergeSortHelper(arr, 0, arr_size - 1);
}



bool Test_MergeSort1() {
	bool testResult; // test comment for commit
	testResult = true;
	int arr[] = { 3,72,6,33,65,98 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int correct[] = { 3,6,33,65,72,98 };
	MergeSort(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] != correct[i]) {
			testResult = false;
			break;
		}
	}
	return testResult;
}
bool Test_MergeSort2() {
	bool testResult = true;
	int size;
	int arr[] = { 9, -1, 6, -5, 11, 4, 5 };
	size = sizeof(arr) / sizeof(arr[0]);

	int correct[] = { -5,-1,4,5,6,9,11 };
	MergeSort(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] != correct[i]) {
			testResult = false;
			break;
		}
	}
	return testResult;
}
bool Test_MergeSort3() {
	int arr[5] = { -5, -3, -10, -2, -7 };
	int correct[5] = { -10,-7,-5,-3,-2, };
	MergeSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		if (arr[i] != correct[i]) {
			return false;
		}
	}
	return true;

}
bool Test_MergeSort4() {

	int bed[5] = { 1000000, 65894, 84759, 41578, 4578421 };
	int correct[5] = { 41578, 65894, 84759 ,1000000, 4578421 };
	MergeSort(bed, 5);
	for (int i = 0; i < 5; i++) {
		if (bed[i] != correct[i]) {
			return false;
		}
	}
	return true;
}
bool Test_MergeSort5() {

	int arr[11] = { 9, -1, 6, -5, 11, 4, 5, 8, -32, -4, -4200000 };
	int correct[11] = { -4200000, -32, -5, -4, -1, 4, 5, 6, 8, 9, 11 };
	MergeSort(arr, 11);
	for (int i = 0; i < 11; i++) {
		if (arr[i] != correct[i]) {
			return false;
		}
	}
	return true;
}
bool Test_MergeSort6() {
	int arr[] = { -12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size - 1);
	for (int i = 0; i < size; i++) {
		if (arr[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int array[] = { 3,72,6,33,65,98 };
	int n = sizeof(array) / sizeof(array[0]);

	std::cout << "Before Merge Sort :" << std::endl;
	PrintArray(array, n);

	MergeSort(array, n);

	std::cout << "After Merge Sort :" << std::endl;
	PrintArray(array, n);
	cout << endl;
	cout << endl;


	cout << "TEST1:" << boolalpha << Test_MergeSort1() << endl;
	cout << "TEST2:" << boolalpha << Test_MergeSort2() << endl;
	cout << "TEST3:" << boolalpha << Test_MergeSort3() << endl;
	cout << "TEST4:" << boolalpha << Test_MergeSort4() << endl;
	cout << "TEST5:" << boolalpha << Test_MergeSort5() << endl;
	cout << "TEST6:" << boolalpha << Test_MergeSort6() << endl;
	cout << endl;
	cout << endl;


	system("pause");
	return (0);
}
