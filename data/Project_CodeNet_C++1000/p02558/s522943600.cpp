#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using lli = int_fast64_t;
using ulli = unsigned long long;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = copy(x);cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl

constexpr lli MOD = (lli)1e9 + 7;
constexpr lli LIMIT = 1000000000000000000 * 5;

int main() {
	int N,Q;
	cin >> N >> Q;
	dsu ds(N);
	while (Q--) {
		int t, v, u;
		cin >> t >> v >> u;

		if (t) {
			cout << ds.same(u, v) << endl;
		}
		else {
			ds.merge(u, v);
		}
	 }



	return 0;
}

