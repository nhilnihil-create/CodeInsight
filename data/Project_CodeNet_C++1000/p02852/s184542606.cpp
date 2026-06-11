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
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	string rs = s;
	reverse(rs.begin(), rs.end());
	int c = 0;
	vector<int> v;
	while (c < rs.size() - 1) {
		int nxt = -1;
		for (int i = c + 1; i < rs.size() && i - c <= M; ++i) {
			if (rs[i] == '0') nxt = i;
		}
		if (nxt == -1) {
			PRI(-1);
			return 0;
		}
		v.push_back(nxt - c);
		c = nxt;
	}
	reverse(v.begin(), v.end());
	for (int x : v)printf("%d ", x);
	printf("\n");
	return 0;
}


