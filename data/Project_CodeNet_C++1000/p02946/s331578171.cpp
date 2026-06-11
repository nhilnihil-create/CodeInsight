#include "bits/stdc++.h"
using namespace std;

int main() {
	int K, X;
	cin >> K >>X;
	int l = max(-1000000,(X - K + 1));
	int r = min(1000000, X + K - 1);
	for (int n = l;n<=r;++n) {
		if (n != l) {
			cout << " ";
		}
		cout << n;
	}
	return 0;
}