#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
	string s, t;
	cin  >> s >> t;
	vector<vector<ll>> dp(s.size(), vector<ll>(26, INF));
	for(ll i = s.size() - 1 ; i > 0; i--)  {
		REP(j, 26) {
			dp[i-1][j] = dp[i][j];
		}
		ll a = s[i] - 'a';
		dp[i-1][a] = i;
	}

	REP(i, 26) {
		dp[s.size()-1][i] = dp[0][i];
	}
	dp[s.size() - 1][s[0] - 'a'] = 0;

	ll cur = s.size()-1;
	ll cnt = 0;
	REP(i, t.size()) {
		if (cur == s.size() -1 && dp[cur][t[i]-'a'] == INF) {
			PRINT(-1);
			return 0;
		}
		if (dp[cur][t[i]-'a'] != INF) {
			if (cur == s.size() - 1) {
				cnt += dp[cur][t[i]-'a']+1;
			} else {
				cnt += dp[cur][t[i]-'a'] - cur;
			}
			cur = dp[cur][t[i]-'a'];
		} else {
			cnt += s.size()-1 - cur;
			cur = s.size()-1;
			i--;
		}
	}
	PRINT(cnt);

	// REP(j, 26) {
	// 	REP(i, s.size()) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	return 0;
}
