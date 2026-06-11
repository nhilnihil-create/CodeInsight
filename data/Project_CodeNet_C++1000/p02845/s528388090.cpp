#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

struct mint {
	ll x;
	mint(ll x = 0) :x(x% mod) {}
	mint& operator+=(const mint a) {
		(x += a.x) %= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		(x += mod - a.x) %= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> color(3, 0);
	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	color[0]++;
	if (a[0] != 0) {
		dunk(0);
		return 0;
	}
	rrep(i, n) {
		bool elf = false;
		ll cnt = 0;
		rep(j, 3) {
			if (a[i] == color[j]) {
				cnt++;
				if (elf) continue;
				color[j]++;
				elf = true;
			}
		}
		dp[i] = (dp[i - 1] * cnt) % mod;
	}
	dp[n - 1] = (dp[n - 1] * 3) % mod;
	cout << dp[n - 1] << endl;
	return 0;
}
