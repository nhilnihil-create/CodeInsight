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

ll N, M;
struct node {
	ll d;
	bool done;
	vector<int> link;
};
vector<node>nod;
ll inf = (ll)1e18;
int main() {
	cin >> N >> M;
	nod.resize(3 * N);
	for (node& n : nod) {
		n.d = inf;
		n.done = false;
	}
	REP(i, 0, M) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		nod[3 * u + 0].link.push_back(3 * v + 1);
		nod[3 * u + 1].link.push_back(3 * v + 2);
		nod[3 * u + 2].link.push_back(3 * v + 0);
	}
	int S, T;
	cin >> S >> T;
	--S; --T;
	nod[3 * S].d = 0;
	auto cmp = [&](int a, int b){
		return nod[a].d > nod[b].d;
	};
	priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
	q.push(3 * S);
	while (!q.empty()) {
		int i = q.top();
		q.pop();
		if (nod[i].done) continue;
		nod[i].done = true;
		for (int c : nod[i].link) {
			if (!nod[c].done && nod[c].d > nod[i].d + 1) {
				q.push(c);
				nod[c].d = nod[i].d + 1;
			}
		}
	}
	if (nod[3 * T].d == inf)PRI(-1);
	else PRI(nod[3 * T].d / 3);
	return 0;
}


