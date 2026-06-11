#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long>> PQ_ASK;


void print_line(vector<string> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}

typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
    color[v] = 1;
    for (auto e: g[v]) {
        if (color[e.dst] == 2) continue;
        if (color[e.dst] == 1) return false;
        if (!visit(g, e.dst, order, color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

bool topologicalSort(const Graph &g, vector<int> &order) {
    int n = g.size();
    vector<int> color(n);
    rep(u, n) if (!color[u] && !visit(g, u, order, color))
            return false;
    reverse(order.begin(), order.end());
    return true;
}


int main() {
    int v, e;
    cin >> v >> e;

    Graph g(v);

    rep(i, e) {
        int s, t;
        cin >> s >> t;
        Edge edge(s, t, 1);

        g[s].push_back(edge);
    }
    vector<int> order;
    topologicalSort(g, order);

    for (int a :order) cout << a << endl;

}

