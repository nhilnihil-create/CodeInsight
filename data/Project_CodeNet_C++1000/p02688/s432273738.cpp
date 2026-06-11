#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	int N, K, d, A;
	int l[100];

	memset(l, 0x00, sizeof(l));
	cin >> N >> K;

	for (int ii = 0; ii < K; ii++) {
		cin >> d;
		for (int jj = 0; jj < d; jj++) {
			cin >> A;
			l[A - 1] += 1;
		}
	}
	int cnt = 0;
	for (int ii = 0; ii < N; ii++) {
		if (l[ii] == 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}