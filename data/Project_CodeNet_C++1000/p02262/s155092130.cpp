#include<iostream>
int cnt;
void insertionSort(int* arr, int len, int g) {
	for (int i = g; i < len; i++) {
		int v = arr[i];
		int j;
		for (j = i - g; j >= 0 && arr[j] > v; j -= g) {
			arr[j + g] = arr[j];
			cnt++;
		}
		arr[j + g] = v;
	}
}
void shellSort(int* arr, int len) {
	using namespace std;
	cnt = 0;
	int m;
	int h = 0;
	for (m = -1; h <= len; m++)
		h = 3 * h + 1;
	cout << m << endl;
	int* G = new int[m];
	G[0] = 1;
	for (int i = 1; i < m; i++) 
		G[i] = 3 * G[i - 1] + 1;
	for (int i = m - 1; i >= 0; i--) {
		if (i != m - 1)
			cout << " " << G[i];
		else
			cout << G[i];
		insertionSort(arr, len, G[i]);
	}
	cout << endl;
	cout << cnt << endl;
}
void printAns(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (i)
			std::cout << " " << arr[i];
		else
			std::cout << arr[i];
	}
	std:: cout << std::endl;
}
int main() {
	using namespace std;
	int len;
	cin >> len;
	int* arr =new int[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	shellSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << endl;
	delete[]arr;
	return 0;
}
