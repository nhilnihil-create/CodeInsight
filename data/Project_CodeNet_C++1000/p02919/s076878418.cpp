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

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<pair<ll, ll>> P(N);
	vector<ll> L1(N), L2(N), R1(N), R2(N);
	REP(i, 0, N) {
		cin >> A[i];
		P[i].first = A[i];//atai
		P[i].second = i;//basho
	}
	sort(P.begin(), P.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.first > b.first; });
	set<ll,greater<ll>> tmp;
	for (ll i = 0; i < N; ++i) {
		auto l1 = tmp.upper_bound(P[i].second);
		if (l1 == tmp.end()) {
			L1[P[i].second] = -1;
			L2[P[i].second] = -1;
		}
		else {
			L1[P[i].second] = *l1;
			auto l2 = tmp.upper_bound(*l1);
			if (l2 == tmp.end()) L2[P[i].second] = -1;
			else L2[P[i].second] = *l2;
		}
		tmp.insert(P[i].second);
	}
	set<ll> tmp2;
	for (ll i = 0; i < N; ++i) {
		auto r1 = tmp2.upper_bound(P[i].second);
		if (r1 == tmp2.end()) {
			R1[P[i].second] = N;
			R2[P[i].second] = N;
		}
		else {
			R1[P[i].second] = *r1;
			auto r2 = tmp2.upper_bound(*r1);
			if (r2 == tmp2.end()) R2[P[i].second] = N;
			else R2[P[i].second] = *r2;
		}
		tmp2.insert(P[i].second);
	}
	ll ans = 0;
	sort(P.begin(), P.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second < b.second; });
	REP(i, 0, N) {
		ans += (P[i].first) * (R1[P[i].second] - P[i].second) * (L1[P[i].second] - L2[P[i].second]);
		ans += (P[i].first) * (R2[P[i].second] - R1[P[i].second]) * (P[i].second - L1[P[i].second]);
	}
	PRI(ans);
	return 0;
}


