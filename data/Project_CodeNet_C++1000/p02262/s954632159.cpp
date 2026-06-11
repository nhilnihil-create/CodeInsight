#include <iostream>
using namespace std;

int cnt;

void insertionSort(int A[], int n, int g)
{
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

void shellSort(int A[], int n)
{
	cnt = 0;
	int G[100];		
	int k, m = 1;
	G[0] = 1;

	while ((k = G[m - 1] * 3 + 1) < n) {
		G[m] = k;
		m++;
	}
	for (int i = 1; i < m; i++)
		G[i] = 3 * G[i - 1] + 1;

	cout << m << "\n";
	for (int i = m - 1; i >= 0; i--) {
		cout << G[i];
		if (i != 0) cout << " ";
	}
	cout << "\n";

	for (int i = m - 1; i >= 0; i--)
		insertionSort(A, n, G[i]);
}

int main()
{
	int n;
	cin >> n;
	int *p = new int[n];

	for (int i = 0; i < n; i++) cin >> p[i];

	shellSort(p, n);
	cout << cnt << "\n";
	for (int i = 0; i < n; i++)
		cout << p[i] << "\n";
	return 0;
}