
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

struct node {
	int id;
	vector<int> link;
};
ll N;
vector<node> nod;
int main() {
	cin >> N;
	nod.resize(N + 1);
	REP(i, 0, N - 1) {
		int u, v;
		cin >> u >> v;
		if (u < v)swap(u, v);
		nod[u].link.push_back(v);
	}
	ll A, B, C, D;
	vector<ll> E(N + 1);
	A = 0; B = 0; C = 0; D = 0;
	REP(L, 1, N + 1) A += N * (N + 1) / 2 - L * (L - 1) / 2 - (N - L + 1) * (L - 1);
	REP(i, 1, N + 1) {
		ll sum = 0;
		for (int c : nod[i].link)sum += c;
		E[i] = i * nod[i].link.size() - sum;
	}
	REP(i, 1, N + 1) D += (N - i + 1) * E[i];
	REP(i, 1, N + 1)C += i * (N - i + 1) * nod[i].link.size();
	B = C - D;
	ll ans = A - B;
	PRI(ans);
	return 0;
}