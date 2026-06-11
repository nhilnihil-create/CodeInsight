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


int main() {
	int N;
	cin >> N;
	vector<ll> a(N);
	vector<ll> b(N);
	REP(i, 0, N)cin >> a[i];
	b[0] = a[1];
	for (int i = 2; i < N; ++i) b[0] ^= a[i];
	for (int i = 1; i < N; ++i) b[i] = a[0] ^ a[i] ^ b[0];
	REP(i, 0, N) PRI(b[i]);
	return 0;
}


