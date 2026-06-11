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
	ll N;
	string s;
	cin >> N;
	cin >> s;
	vector<vector<ll>> dp(N+1);
	REP(i, 0, N + 1) dp[i].resize(N + 1, 0);
	REP(i, 1, N + 1) {
		REP(j, 1, N + 1) {
			if (s[i-1] == s[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	ll ans = 0;
	REP(i, 0, N + 1)REP(j, 0, N + 1) ans = max(ans, min(dp[i][j], max(i, j) - min(i, j)));
	PRI(ans);
	return 0;
}


