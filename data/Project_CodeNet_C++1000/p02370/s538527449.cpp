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

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cerr << C << endl;
#define VI vector <int>
#define VII vector <VI>
#define VL vector <LL>
#define VLL vector <VL>
#define VD vector <double>
#define VDD vector <VD>
#define PII pair <int, int>
#define PDD pair <double, double>
#define PLL pair <LL, LL>
#define VPII vector <PII>
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, e) (s.find(e) != s.end())
#define EB emplace_back

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

class TopologicalSort {
private:
    vector <bool> is;
    vector <vector <int>> g;
    vector <int> tsort;
    void dfs(int now) {
        if (is[now]) return;
        is[now] = true;
        for (auto &&el:g[now]) {
            dfs(el);
        }
        tsort.emplace_back(now);
    }
public:
    TopologicalSort() {}
    TopologicalSort(vector <vector <int>> graph) {
        g = graph;
        is.resize(g.size());
    }
    vector <int> sort() {
        for (int i = 0; i < g.size(); i++) {
            dfs(i);
        }
        reverse(tsort.begin(), tsort.end());
        return tsort;
    }
};

int main(void) {
    int V, E;
    VII graph;
    cin >> V >> E;
    graph.resize(V);
    REP(i, E) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].EB(b);
    }
    TopologicalSort ts(graph);
    auto ans = ts.sort();
    FORE(el, ans) cout << el << endl;
}