#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

static const ll INF = 1e15;
const ll mod = 1e9 + 7;

int main(void)
{
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<ll>> dp(100010, vector<ll>(2, 0));
	constexpr int low = 0;
	constexpr int eq = 1;
	dp[0][low] = 1;
	dp[0][eq] = 2;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1') {
			dp[i][low] = dp[i - 1][low] * 3;
			dp[i][low] += dp[i - 1][eq];
			dp[i][eq] = dp[i - 1][eq] * 2;
		}
		else {
			dp[i][low] = dp[i - 1][low] * 3;
			dp[i][eq] = dp[i - 1][eq];
		}
		dp[i][low] %= mod;
		dp[i][eq] %= mod;
	}
	cout << (dp[n-1][low] + dp[n-1][eq]) % mod << endl;

}
