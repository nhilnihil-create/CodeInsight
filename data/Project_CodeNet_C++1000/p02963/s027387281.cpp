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
	ll S; cin >> S;
	ll x2 = 1e9;
	ll x3 = (x2-S%x2)%x2;
	ll y3 = (S + x3) / x2;

	std::cout << "0 0 1000000000 1 " << x3 << " " << y3 << std::endl;
}