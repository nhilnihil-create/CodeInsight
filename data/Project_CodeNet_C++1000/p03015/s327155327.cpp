#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<double, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
	if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
	if (ref < value) ref = value;
}

const ll mod = 1000000007;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<bool> vs(n);
	rep(i, n) {
		vs[i] = (s[i] == '1');
	}
	vector<vector<ll>> dp(n, vector<ll>(2, 0));
	//dp[i][j]...j==true : eqal
	//dp[i][j]...j==false : lower
	dp[0][0] = 1;
	dp[0][1] = 2;
	for (int i = 1; i < n; i++) {
		if (vs[i]) {
			//00
			dp[i][0] += dp[i - 1][1];
			//00
			dp[i][0] += dp[i - 1][0];
			//10, 01
			dp[i][0] += 2 * dp[i - 1][0];

			//10, 01
			dp[i][1] += 2 * dp[i - 1][1];
		}
		else {
			//00
			dp[i][0] += dp[i - 1][0];
			//10, 01
			dp[i][0] += 2 * dp[i - 1][0];

			//00
			dp[i][1] += dp[i - 1][1];
		}
		rep(j, 2) {
			dp[i][j] %= mod;
		}
	}
	ll sum = dp[n - 1][0] + dp[n - 1][1];
	sum %= mod;
	cout << sum << endl;
	return 0;
}
