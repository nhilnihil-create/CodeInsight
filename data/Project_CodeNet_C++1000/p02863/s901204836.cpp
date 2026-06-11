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


vector<vector<ll>> dp1(3010, vector<ll>(3010, 0));
vector<vector<ll>> dp2(3010, vector<ll>(3010, 0));

int main(int argc, char **argv)
{
	ll N, T; cin >> N >> T;
	vector<ll> A(N), B(N);
	REP(i, N)
		cin >> A[i] >> B[i];

	REP(n, N)REP(t, T)
	{
		chmax(dp1[n+1][t], dp1[n][t]);
		if (t-A[n] >= 0) chmax(dp1[n+1][t], dp1[n][t-A[n]]+B[n]);
	}

	for (ll n = N; n > 0; --n)
	{
		REP(t, T)
		{
			chmax(dp2[n-1][t], dp2[n][t]);
			if (t - A[n-1] >= 0) chmax(dp2[n-1][t], dp2[n][t-A[n-1]]+B[n-1]);
		}
	}
	
	ll res{0};
	REP(i, N)
	{
		REP(j, T)
		{
			ll tmp = B[i] + dp1[i][j] + dp2[i+1][T-1-j];
			chmax(res, tmp);
		}
	}

	std::cout << res << std::endl;
}
