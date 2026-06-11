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
#define DEBUG(x) ;
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};



int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N; cin >> N;
	vector<pair<ll, ll>> xy;
	REP(i, N)
	{
		ll a, b; cin >> a >> b;
		xy.push_back(P{a, b});
	}

	// z = x + y;
	// w = x - y;
	ll zma, zmi, wma, wmi; 
	zma = wma = -INF;
	zmi = wmi = INF;
	
	REP(i, N)
	{
		zma = max(zma, xy[i].first + xy[i].second);
		zmi = min(zmi, xy[i].first + xy[i].second);

		wma = max(wma, xy[i].first - xy[i].second);
		wmi = min(wmi, xy[i].first - xy[i].second);
	}

	std::cout << max(zma - zmi, wma - wmi) << std::endl;
}
