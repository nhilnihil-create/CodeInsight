#include <iostream>
#include <vector>

using namespace std;

void printa(int A[], int len, string separator) {
	cout << A[0];
	for (int i = 1; i < len; i++)
		cout << separator << A[i];
	cout << endl;
}

int insertionSort(int A[], int len, int g) {
	int cnt = 0;
	for (int i = g; i < len; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
	return cnt;
}

void shellSort(int A[], int len) {
	int cnt = 0;
	vector<int> G;
	for (int h = 1; h <= len; h = 3 * h + 1)
		G.insert(G.begin(), h);
	int m = G.size();

	for (int i = 0; i < m; i++)
		cnt += insertionSort(A, len, G[i]);

	cout << m << endl;
	printa(G.data(), m, " ");
	cout << cnt << endl;
	printa(A, len, "\n");
}

int main() {
	int n, *a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	shellSort(a, n);
	delete[] a;
	return 0;
}