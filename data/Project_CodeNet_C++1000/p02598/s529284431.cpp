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

ll N, K;
vector<ll> A;

bool check(ll x) {
	ll sum = 0;
	REP(i, 0, A.size()) sum += (A[i] + x - 1) / x - 1;
	return sum <= K;
}

int main() {
	cin >> N >> K;
	A.resize(N);
	REP(i, 0, N)cin >> A[i];
	if (K == 0) {
		PRI(*max_element(A.begin(), A.end()));
		return 0;
	}
	ll l = 1;
	ll r = 1000000000;
	while (true) {
		if (l == r) {
			PRI(l);
			return 0;
		}

		ll center = (l + r) / 2;
		if (check(center)) r = center;
		else l = center+1;
	}

	return 0;
}


