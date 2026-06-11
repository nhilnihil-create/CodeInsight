#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338327950L

int gcd(int x, int y) {
	int r;
	while ((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}

int main() {
	int K;
	long long sum = 0;
	cin >> K;
	for (int ii = 1; ii <= K; ii++) {
		for (int jj = 1; jj <= K; jj++) {
			for (int kk = 1; kk <= K; kk++) {
				sum += gcd(gcd(ii, jj), kk);
			}
		}
	}
	cout << sum << endl;
}
