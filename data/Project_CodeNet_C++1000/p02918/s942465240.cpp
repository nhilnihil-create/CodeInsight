#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	ll a{0};

	REP(i, n-1)
	{
		a += s[i] != s[i+1];
	}
	std::cout << n-1-max(a-2*k, 0ll)<< std::endl;
}
