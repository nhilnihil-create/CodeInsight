#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

#define MAX 12
#define SUM_INIT 10000000000

int main() {
	int N, M, X;
	int C[MAX];
	int A[MAX][MAX];

	cin >> N >> M >> X;

	for (int ii = 0; ii < N; ii++) {
		cin >> C[ii];
		for (int jj = 0; jj < M; jj++) {
			cin >> A[ii][jj];
		}
	}

	long long sum = SUM_INIT, tmp = 0;
	int U[MAX];
	for (int ii = 0; ii < 1 << N; ii++) {
		memset(U, 0x00, sizeof(U));
		tmp = 0;
		for (int jj = 0; jj < N; jj++) {
			if (((ii >> jj) & 1) == 0) {
				continue;
			}
			for (int kk = 0; kk < M; kk++) {
				U[kk] += A[jj][kk];
			}
			tmp += C[jj];
		}
		for (int jj = 0; jj < M; jj++) {
			if (U[jj] < X) {
				break;
			}
			if (jj == M - 1) {
				if (tmp < sum) {
					sum = tmp;
				}
			}
		}
	}
	if (sum == SUM_INIT) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
	}
	
	return 0;

}