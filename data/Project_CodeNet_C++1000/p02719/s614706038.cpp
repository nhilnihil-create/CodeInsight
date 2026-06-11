#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	ll div = N / K;
	ll mod = N % K;

	if (mod == 0) {
		ans = 0;
	} else if (mod < (K / 2)) {
		ans = mod;
	}
	else {
		ans = K - mod;
	}
	
	cout << ans << endl;
	return 0;
}
