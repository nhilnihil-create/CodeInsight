#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
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

char F[110][110];
ll dp[110][110];

int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	REP(h, H) REP(w, W)
	{
		dp[h][w] = INF;
		cin >> F[h][w];
	}

	if (F[0][0] == '#')
		dp[0][0] = 1;
	else
		dp[0][0] = 0;

	REP(h, H)
	{
		REP(w, W)
		{
			chmin(dp[h][w+1], dp[h][w] + (F[h][w] == '.' && F[h][w+1] == '#'));
			chmin(dp[h+1][w], dp[h][w] + (F[h][w] == '.' && F[h+1][w] == '#'));
		}
	}

	std::cout << dp[H-1][W-1] << std::endl;
}
