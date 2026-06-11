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

template<class T>
bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, initializer_list<T> l)
{
	return chmax(a, *max_element(l.begin(), l.end()));
}

template<class T>
bool chmin(T &a, initializer_list<T> l)
{
	return chmin(a, *min_element(l.begin(), l.end));
}


const ll MAX_N = 15;
const ll MAX_M = 1010;
ll dp[1ll<<MAX_N][MAX_M];
ll A[MAX_M]{};
ll B[MAX_M]{};
ll C[MAX_M]{};

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	REP(m, M)
	{
		cin >> A[m] >> B[m];
		REP(c, B[m])
		{
			ll t; cin >> t;
			--t;
			C[m] |= (1ll<<t);
		}
	}

	ll BMAX = 1ll<<N;

	REP(b, BMAX) REP(m, MAX_M) dp[b][m] = INF;
	**dp = 0;


	REP(b, BMAX)
	{
		REP(m, M)
		{
			chmin(dp[b][m+1], dp[b][m]);
			ll tmp = b | C[m];
			chmin(dp[tmp][m+1], dp[b][m] + A[m]);
		}
	}

	ll res = dp[BMAX-1][M];
	std::cout << (res == INF ? -1 : res) << std::endl;
	
}
