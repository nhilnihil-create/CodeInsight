#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	long long N;
	cin >> N;
	if (1 == N%2) {
		cout << 0 << endl;
	}
	else {
		N /= 2;
		long long ans = 0;
		while (0 != N) {
			ans += N / 5;
			N /= 5;
		}
		cout << ans << endl;
	}
	return 0;
}	