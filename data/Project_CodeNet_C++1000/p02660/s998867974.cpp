#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	ll ncpy = n;
	for (ll i = 2; i * i <= ncpy; i++) {
		int q = i;
		while(n % q == 0) {
			n /= q;
			q *= i;
			ans++;
		}
		while(n % i == 0) n /= i;
	}
	if (n > 1) ans++;
	cout << ans << endl;
	return 0;
}
