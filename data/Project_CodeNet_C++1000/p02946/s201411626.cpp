#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int K, X; cin >> K >> X;
	rep(i, 2 * K - 1) {
		cout << X - K + 1 + i << " ";
	}
}