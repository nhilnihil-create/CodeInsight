
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
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

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
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };


int main() {
	multimap<ll, ll> mp;
	priority_queue<ll, vector<ll>> q;
	ll N, M;
	cin >> N >> M;
	REP(i, 0, N) {
		ll a, b;
		cin >> a >> b;
		mp.insert(pair<ll, ll>{a, b});
	}
	ll ans = 0;
	for (int i = M - 1; i >= 0; --i) {
		auto range = mp.equal_range(M - i);
		for (auto itr = range.first; itr != range.second; ++itr) {
			q.push(itr->second);
		}
		if (q.empty())continue;
		ans += q.top();
		q.pop();
	}
	PRI(ans);
	return 0;
}