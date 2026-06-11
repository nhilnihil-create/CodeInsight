#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define inputSpeed() ios_base::sync_with_stdio(0),cin.tie(0)
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {} template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...);}
#define MOD 998244353

ll mPower(ll b, ll e) {
	ll ans = 1;
	while (e) {
		if (e&1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

int main () {
	inputSpeed();

	int N, S;
	cin >> N >> S;
	int A[N+5];
	for (int i = 0; i < N; i++) cin >> A[i];

	ll dp[N+5][S+5];
	ll inv2 = mPower(2, MOD-2);

	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (!i) {
				if (j) dp[i][j] = 0;
				else dp[i][j] = mPower(2, N);
			} else {
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD; // Same result from before
				if (j-A[i-1] >= 0) dp[i][j] = (dp[i][j] + ((dp[i-1][j-A[i-1]] * inv2) % MOD)) % MOD;
			}
		}
	}

	printf("%lld\n", dp[N][S]);
}
