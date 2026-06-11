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
	vector<ll> a, b;
	int N;
	cin >> N;
	REP(i, 0, N) {
		ll a_, b_;
		cin >> a_ >> b_;
		a.push_back(a_);
		b.push_back(b_);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (N % 2 == 1) {
		PRI(b[N / 2] - a[N / 2] + 1);
	}
	else {
		PRI((b[N / 2 - 1] + b[N / 2]) - (a[N / 2 - 1] + a[N / 2]) + 1);
	}
	return 0;
}


