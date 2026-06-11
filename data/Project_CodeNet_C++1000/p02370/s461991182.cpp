#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <random>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

template<typename T>
class TopologicalSort {
private:
    map<T, bool> is;
    map<T, vector<T>> g;
    vector<T> tsort;
	map<T, long long> inCnt;
    void dfs(T now) {
        if (is[now]) return;
		is[now] = true;
        for (auto &&el : g[now]) {
            dfs(el);
        }
        tsort.emplace_back(now);
    }
public:
    TopologicalSort() {}
	TopologicalSort(const vector<T>& vec) {
		for (auto &&el : vec) {
			g[el].resize(0);
			is[el] = false;
		}
	}
    vector<T> dfsTsort() {
        for (auto &&el : g) {
            dfs(el.first);
        }
        reverse(tsort.begin(), tsort.end());
        return tsort;
    }
	void addEdge(T src, T dst) {
		g[src].emplace_back(dst);
		inCnt[dst]++;
	}
	vector<T> bfsTsort() {
		queue<T> q;
		for (auto &&el : inCnt) {
			if (el.second == 0) {
				q.push(el.first);
			}
		}
		while (!q.empty()) {
			T now = q.front(); q.pop();
			tsort.emplace_back(now);
			for (auto &&el : g[now]) {
				if (--inCnt[el] == 0) q.push(el);
			}
		}
		bool endFlag = true;
		for (auto &&el : inCnt) {
			if (el.second) endFlag = false;
		}
		return (endFlag ? tsort : vector<T>());
	}
};

int main(void) {
	int V, E;
	cin >> V >> E;
	VI v(V);
	iota(ALL(v), 0);
	TopologicalSort<int> t(v);
	REP(_, E) {
		int s, d;
		cin >> s >> d;
		t.addEdge(s, d);
	}
	auto ans = t.dfsTsort();
	FORE(el, ans) cout << el << endl;
}