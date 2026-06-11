#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

string s;
ll dp[100010][13];

int main(int argc, char **argv)
{
	cin >> s;
	ll N = s.size();

	**dp = 1;

	REP(n, N)
	{
		REP(j, 13)
		{
			if (s[n] == '?')
				REP(k, 10)
				{
					(dp[n+1][(j*10+k)%13] += dp[n][j]) %= MOD;
				}
			else
				(dp[n+1][(j*10+(s[n]-'0'))%13] += dp[n][j]) %= MOD;
		}
	}

	std::cout << dp[N][5] << std::endl;
}
