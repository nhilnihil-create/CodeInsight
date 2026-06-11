#include <iostream>
#include <cmath>

using namespace std;

static const int m_MAX = 100;
static const int n_MAX = 1000000;

int insertionSort(int A[], int n, int g) {
	int i, j, v, cnt = 0;

	for (i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
			A[j+g] = v;
		}
	}

	return cnt;
}

void shellSort(int A[], int n) {
	int i, j, m, G[m_MAX], cnt = 0;

	G[0] = 1;
	for (i = 1; G[i - 1] * 3 + 1 < n; i++)
		G[i] = G[i - 1] * 3 + 1;
	m = i;

	cout << m << endl;

	cout << G[m-1];
	for (i = m - 2; i >= 0; i--)
		cout << ' ' << G[i];
	cout << endl;


	for (i = m - 1; i >= 0; i--)
		cnt += insertionSort(A, n, G[i]);

	cout << cnt << endl;

	for (i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
}

int main () {
	int n, i, A[n_MAX];

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];

	shellSort(A, n);

	return 0;
}