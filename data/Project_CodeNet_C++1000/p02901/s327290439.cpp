#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> dp(M + 1);
	ll inf = (ll)1e18;
	REP(i, 0, M + 1)dp[i].resize(4096, inf);
	dp[0][0] = 0;
	REP(i, 1, M + 1) {
		ll a, b, f = 0;
		cin >> a >> b;
		REP(j, 0, b) {
			ll c;
			cin >> c;
			f |= (1 << (c - 1));
		}
		REP(j, 0, 4096) {
			dp[i][j] = dp[i - 1][j];
			ll xx = ~(f);
			ll x = j & (xx);
			ll y = dp[i - 1][x];
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], y+a));
		}
	}
	ll f = 0;
	REP(i, 0, N) f |= (1 << i);
	if (dp[M][f] >= inf) PRI(-1);
	else PRI(dp[M][f]);
	return 0;
}


