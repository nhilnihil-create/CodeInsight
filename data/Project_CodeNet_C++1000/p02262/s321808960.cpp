#include <cstdio>
#include <iostream>

using namespace std;

//insertionSort(A, n, g)
//    for i = g to n-1
//        v = A[i]
//        j = i - g
//        while j >= 0 && A[j] > v
//            A[j+g] = A[j]
//            j = j - g
//            cnt++
//        A[j+g] = v
//
//shellSort(A, n)
//    cnt = 0
//    m = ?
//    G[] = {?, ?,..., ?}
//    for i = 0 to m-1
//        insertionSort(A, n, G[i])

int cnt = 0;
void insertionSort(int A[], int n, int g) {
	for (int i = g; i < n; ++i) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[], int n) {
	cnt = 0;
	int g = 0;
	int m = -1;
	while (g <= n) {
		g = g * 3 + 1;
		++m;
	}

	int G[m];
	g = (g - 1) / 3;
	for (int i = 0; i < m; ++i) {
		G[i] = g;
		g = (g - 1) / 3;
	}
	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		if (i != 0)
			cout << " " << G[i];
		else
			cout << G[i];
	}
	cout << endl;
	for (int i = 0; i < m; ++i) {
		insertionSort(A, n, G[i]);
	}
}
int main() {

	int n;
	scanf("%d", &n);

	int A[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", A + i);
	}

	shellSort(A, n);

	cout << cnt << endl;

	for (int i = 0; i < n; ++i) {
		cout << A[i] << endl;
	}

	return 0;
}