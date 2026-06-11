#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll modpow(int p, int q) {
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

int main() {

	int n, k;
	cin >> n >> k;
	V<ll> an(k);
	ll sum = 0;


	for (int i = k;i > 0;i--) {

		ll pt = modpow((k / i), n);
		for (int j = 2;i * j <= k;j++) { pt -= an[i * j - 1];if (pt < 0)pt += MOD; }
		an[i - 1] = pt;
		sum += an[i - 1] * i % MOD;
		sum %= MOD;

	}

	cout << sum << endl;

}