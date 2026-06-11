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
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define MINS(a,b) a = min(a,(decltype(a))(b))
#define MAXS(a,b) a = max(a,(decltype(a))(b))


int main() {
	ll N;
	cin >> N;
	vector<pair<ll,ll>> P(N);
	
	REP(i, 0, N) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P.begin(), P.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {return atan2l(a.second, a.first) < atan2l(b.second, b.first); });

	ldb ans = 0;
	REP(i, 0, N) {
		REP(j, i, i + N) {
			pair<ll, ll> p = { 0,0 };
			REP(k, i, j + 1) {
				p.first += P[k % N].first;
				p.second += P[k % N].second;
			}
			MAXS(ans, sqrtl(p.first* p.first + p.second * p.second));
		}
	}
	printf("%.11Lf\n", ans);
	return 0;
}


