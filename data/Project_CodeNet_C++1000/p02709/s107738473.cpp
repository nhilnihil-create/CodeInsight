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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


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


vector<pair<int,ll>> A;
vector<vector<ll>> dp;
int N;


int main() {
	cin >> N;
	A.resize(N);
	dp.resize(N+1);
	REP(i, 0, N + 1)dp[i].resize(N + 1, 0);
	REP(i, 0, N) {
		ll a;
		cin >> a;
		A[i] = pair<int, ll>(i + 1, a);
	}
	sort(A.begin(), A.end(), [](pair<int, ll> a, pair<int, ll> b) {return a.second > b.second; });
	REP(i, 0, N) dp[i + 1][0] = dp[i][0] + A[i].second * (N - i - A[i].first);
	REP(j, 0, N) dp[0][j + 1] = dp[0][j] + A[j].second * (A[j].first - j - 1);
	REP(i, 0, N) {
		REP(j, 0, N) {
			if (i + 1 + j + 1 > N) continue;
			dp[i + 1][j + 1] = max(
				dp[i][j + 1] + A[i + j + 1].second * (N - i - A[i + j + 1].first),
				dp[i + 1][j] + A[i + j + 1].second * (A[i + j + 1].first - j - 1)
				);
		}
	}
	ll ans = 0;
	REP(i, 0, N+1)ans = max(ans, dp[i][N - i]);
	PRI(ans);
	return 0;
}


