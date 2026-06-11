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

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	vector<ll> F(N);
	REP(i, 0, N) cin >> A[i];
	REP(i, 0, N) cin >> F[i];
	sort(A.begin(), A.end(), greater<ll>());
	sort(F.begin(), F.end(), less<ll>());
	auto calc = [&](ll X) {
		ll ret = 0;
		REP(i, 0, N) ret += max(A[i] - X / F[i], 0LL);
		return ret;
	};
	ll l = -1;
	ll r = (ll)1e18;
	while (r - l > 1) {
		ll mid = l + (r - l) / 2;
		if (calc(mid) <= K) r = mid;
		else l = mid;
	}
	PRI(r);
	return 0;
}


