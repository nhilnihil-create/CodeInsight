#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int l = m / 2;
	int l2 = m - l;//こっちのがおおい
	//1  .... 2*l2
	for (int n = 1;n <= l2;++n) {
		cout << n <<" "<< 2 * l2  + 1- n << endl;
	}
	// 2l+1......(2l + l2 *2)
	for (int n = 1;n <= l;++n) {
		cout << 2 * l2 + n << " " << 2 * l2 + 2 * (l + 1) - n << endl;
	}
	return 0;
}