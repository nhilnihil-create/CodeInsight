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


const ll MAXN = 13;
const ll MAXM = 1010;
ll dp[MAXM][1ll<<MAXN];
ll N, M;
ll A[MAXM];
ll B[MAXM];
ll C[MAXM]{};

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	REP(m, M)
	{
		cin >> A[m] >> B[m];
		REP(i, B[m])
		{
			ll t;
			cin >> t;
			--t;
			C[m] |= (1ll<<t);
		}
	}

	ll BMAX = 1ll<<N;
	REP(b, BMAX)REP(m, MAXM) dp[m][b] = INF;
	**dp = 0;
	
	REP(i, M)
	{
		REP(bits, BMAX)
		{
			chmin(dp[i+1][bits], dp[i][bits]);
			ll boxs = bits | C[i];
			chmin(dp[i+1][boxs], dp[i][bits]+A[i]);
		}
	}

	ll res = dp[M][BMAX-1];
	std::cout << (res == INF ? -1 : res) << std::endl;
}
