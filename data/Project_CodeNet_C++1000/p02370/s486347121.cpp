#include "bits/stdc++.h"
#include <unordered_set>

#define _CRT_SECURE_NO_WARNINGS

#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define REP2(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP3(i, x, n) for(decltype(x) i = (x); i <= (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1; i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

using namespace std;

// N, E, S, W
const int dx[4] = { 1, 0, -1, 0};
const int dy[4] = { 0, 1, 0, -1};

using LL = long long int;
using LD = long double;

const int INF = (1 << 30) - 1;
const LL INF64 = ((LL)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<LL>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;

//==============================================

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	vvi G(v);
	vi indeg(v);
	REP(i, e) {
		int s, t;
		cin >> s >> t;

		G[s].push_back(t);
		indeg[t]++;
	}


	vi ans;
	queue<int> q;
	REP(i, v) {
		if (indeg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();

		ans.push_back(u);

		for (int v : G[u]) {
			indeg[v]--;

			if (indeg[v] == 0) q.push(v);
		}
	}

	for (int a : ans) cout << a << endl;
	return 0;
}