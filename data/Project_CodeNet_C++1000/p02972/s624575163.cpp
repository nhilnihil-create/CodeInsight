#include <bits/stdc++.h>
using namespace std;

#define MAX 200000
int N;
int a[MAX + 1];
int A[MAX + 1];
int M = 0;
int b[MAX];
int r = 1;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		A[i] = 0;
		cin >> a[i];
	}
	for (int i = N; i > 0; i--) {
		int sum = 0;
		for (int j = 2 * i; j <= N; j += i) {
			sum += A[j];
		}
		A[i] = (sum % 2 == a[i] ? 0 : 1);
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) {
			M++;
			b[r++] = i;
		}
	}
	cout << M << endl;
	for (int i = 1; i <= M; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}