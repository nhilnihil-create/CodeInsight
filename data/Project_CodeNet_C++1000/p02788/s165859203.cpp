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
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define MINS(a,b) a = min(a,(decltype(a))(b))
#define MAXS(a,b) a = max(a,(decltype(a))(b))



int main() {
	ll N, D, A;
	cin >> N >> D >> A;
	vector<pair<ll, ll>> V(N);
	vector<ll> C(N);
	REP(i, 0, N) {
		cin >> V[i].first >> V[i].second;
		C[i] = 0;
	}
	auto cmp = [](const pair<ll,ll>& a,const pair<ll, ll>& b) {return a.first < b.first; };
	sort(V.begin(), V.end(), cmp);
	ll ans = 0, cur = 0;
	REP(i, 0, N) {
		ll n = (V[i].second + cur + A - 1) / A;
		MAXS(n, 0);
		ans += n;
		C[i] += -n * A;
		int j = distance(V.begin(), upper_bound(V.begin(), V.end(), pair<ll,ll>{ V[i].first + 2 * D, 0 }, cmp)) - 1;
		C[j] += n * A;
		cur += C[i];
	}
	PRI(ans);
	return 0;
}


