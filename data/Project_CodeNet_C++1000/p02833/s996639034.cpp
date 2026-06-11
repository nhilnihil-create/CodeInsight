#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	if (n % 2 == 1) ans = 0;
	else {
		n /= 2;
		while (n >= 5) {
			n /= 5;
			ans += n;
		}
	}
	cout << ans << endl;
	return 0;
}