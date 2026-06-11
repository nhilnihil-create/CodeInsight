#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

VVI graph;
VI parent;
VL ans, counter;

void build_tree(int i) {
    for (int adj : graph[i]) {
        if (parent[adj] != -1) continue;
        parent[adj] = i;
        build_tree(adj);
    }
}

ll dfs(int i) {
    if (ans[i] != -1) return ans[i];
    if (i == 0) return ans[i] = counter[i];
    return ans[i] = counter[i] + dfs(parent[i]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    graph.resize(n);
    parent.resize(n, -1);
    counter.resize(n, 0);
    ans.resize(n, -1);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    build_tree(0);

    REP(i, q) {
        ll p, x;
        cin >> p >> x;
        counter[p - 1] += x;
    }

    REP(i, n) {
        cout << dfs(i);
        if (i == n - 1)
            cout << ln;
        else
            cout << " ";
    }
    return 0;
}
