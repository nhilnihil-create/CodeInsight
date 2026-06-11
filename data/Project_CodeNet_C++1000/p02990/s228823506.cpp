#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll lpow(int p, int q) {
	ll ans = 1;
	ll pp = p;
	while (q) {
		if (q % 2) {
			ans *= pp;
			ans %= MOD;
		}
		q /= 2;
		pp *= pp;
		pp %= MOD;
	}
	return ans;
}


ll com(int n, int r) {
	if(n<r||n<0||r<0)	return 0;
	ll ans = 1;
	int k = n - r;

	rep1(i, n) {
		ans *= i;
		ans %= MOD;
	}

	rep1(i, r) {
		ans *= lpow(i, MOD - 2);
		ans %= MOD;
	}

	rep1(i, k) {
		ans *= lpow(i, MOD - 2);
		ans %= MOD;
	}

	return ans;
}




int main() {

	int n, k;
	cin >> n >> k;

	rep1(i, k) {
		ll ans = (com(n - k + 1, i) * com(k - 1, i - 1)) % MOD;
		cout << ans << endl;
	}
}