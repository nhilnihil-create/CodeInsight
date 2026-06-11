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



ll key(int i, int j) {
	return ((ll)(max(i, j)) << 32) | (ll)(min(i, j));
}
struct node {
	int state;
	int d;
	vector<ll> to;
};
unordered_map<ll, node> mp;
vector<ll> t;
int N;
bool dag = true;
void visit(ll k) {
	if (mp[k].state == 1) {
		dag = false;
		return;
	}
	else if (mp[k].state == 0) {
		mp[k].state = 1;
		for (ll& ck : mp[k].to) visit(ck);
		mp[k].state = 2;
		t.push_back(k);
	}
}
int main() {
	cin >> N;
	REP(i, 0, N - 1)REP(j, i + 1, N)mp.insert(pair<ll, node>(key(i, j), node{ 0 ,0 }));
	REP(i, 0, N) {
		vector<int> a(N - 1);
		REP(j, 0, N - 1) cin >> a[j];
		REP(j, 0, N - 2)mp[key(i, a[j]-1)].to.push_back(key(i, a[j + 1]-1));
	}
	for (auto p : mp) {
		if (p.second.state == 0) visit(p.first);
	}
	if (!dag) {
		PRI(-1);
		return 0;
	}
	int ans = 0;
	for (ll& k : t) {
		for (ll ck : mp[k].to) {
			mp[k].d = max(mp[k].d, mp[ck].d + 1);
			ans = max(ans, mp[k].d);
		}
	}
	PRI(ans+1);
	return 0;
}


