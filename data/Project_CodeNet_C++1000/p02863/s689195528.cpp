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

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll N, T;
	cin >> N >> T;
	vector<pair<ll, ll>> p(N);
	vector<vector<ll>> dp(N + 1);
	REP(i, 0, N) cin >> p[i].first >> p[i].second; 
	sort(p.begin(), p.end(), [](auto& a, auto& b) {return a.first < b.first; });
	REP(i, 0, N + 1) dp[i].resize(T, 0);
	ll ans = p[0].second;
	REP(i, 1, N) {
		REP(t, 1, T) {
			dp[i][t] = max(dp[i - 1][t], dp[i][t - 1]);
			if (t - p[i - 1].first >= 0) dp[i][t] = max(dp[i][t], dp[i - 1][t - p[i - 1].first] + p[i - 1].second);
		}
		ans = max(ans, dp[i][T - 1] + p[i].second);
	}
	PRI(ans);
	return 0;
}


