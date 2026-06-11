#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N, R; cin >> N >> R;
	if (N <= 10)
	{
		std::cout << R + 100*(10-N) << std::endl;
	}
	else
		std::cout << R << std::endl;
}
