#include<iostream>
#include<vector>
using namespace std;
long cnt = 0;
vector<int> G;
void InsertionSort(int A[], int n, int g) {
	for (int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}
void ShellSort(int A[], int n) {
	for (int h = 1;;) {
		if (h > n)
			break;
		G.push_back(h);
		h = h * 3 + 1;
	}
	for (int i = G.size() - 1; i >= 0; i--) {
		InsertionSort(A, n, G[i]);
	}
}
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ShellSort(arr, n);
	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--) {
		cout << G[i];
		if (i != 0) {
			cout << ' ';
		}
	}
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}
