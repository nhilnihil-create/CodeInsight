
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

ll N, K;
vector<ll> P, C;

void f(int ind, unordered_set<int>& buf, vector<ll>& pass, vector<ll>& sum) {
	if (pass.empty()) sum.push_back(0);
	else sum.push_back(sum.back() + C[pass.back()]);
	pass.push_back(ind);
	if (buf.count(ind) == 0) {
		buf.insert(ind);
		f(P[ind], buf, pass, sum);
	}
}

ll query(int ind) {
	unordered_set<int> buf;
	vector<ll> pass, sum;
	f(ind, buf, pass, sum);
	int loopstart;
	REP(i, 0, pass.size() - 1) {
		if (pass[i] == pass.back()) {
			loopstart = i;
			break;
		}
	}
	ll noloop_mx = -1e18;
	for (int i = 1; i <= K && i < sum.size(); ++i)maxs(noloop_mx, sum[i]);
	if (K <= sum.size() - 1) return noloop_mx;

	ll loop_score = sum.back() - sum[loopstart];
	if (loop_score <= 0) return noloop_mx;
	ll loop_length = sum.size() - loopstart-1;
	ll loop_n = (K - loopstart) / loop_length;
	ll amari = (K - loopstart) % loop_length;
	ll i0 = sum.size() + amari - loop_length;
	ll tmp = sum[loopstart] + loop_n * loop_score - (sum.back() - sum[i0]);
	ll ans = tmp;
	for (int i = 1; i < loop_length; ++i) {
		int ind = i0 + i;
		if (ind >= sum.size()) ind -= loop_length;
		tmp += sum[ind] - sum[ind - 1];
		maxs(ans, tmp);
	}
	return max(ans, noloop_mx);
}

int main() {
	cin >> N >> K;
	P.resize(N);
	C.resize(N);
	REP(i, 0, N) {
		cin >> P[i];
		--P[i];
	}
	REP(i, 0, N) cin >> C[i];
	ll ans = -1e18;
	REP(i, 0, N) maxs(ans, query(i));
	PRI(ans);
	return 0;
}