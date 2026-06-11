#include <bits/stdc++.h>
using ll = long long;
using namespace std;

using Weight = int;

struct edge
{
    int from, to;
    Weight weight;
};

using Edges = std::vector<edge>;
using Graph = std::vector<Edges>;

const Weight winf = numeric_limits<Weight>::max();

vector<Weight> bellman_ford(const Edges& es, int V, int s)
{
    vector<Weight> dst(V, winf);
    dst[s] = 0;

    for (int i = 0; i < V; i++) {
        for (auto& e: es) {
            if (dst[e.from] != winf && dst[e.to] > dst[e.from] + e.weight) {
                dst[e.to] = dst[e.from] + e.weight;
                if (i == V - 1) return vector<Weight> ();
            }
        }
    }
    return dst;
}

int main()
{
    int v, e, r; cin >> v >> e >> r;
    Edges es;
    for (int i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        es.push_back({s, t, d});
    }

    auto bf = bellman_ford(es, v, r);
    if (bf.empty()) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int i = 0; i < v; i++) {
            cout << (bf[i] == winf ? "INF" : to_string(bf[i])) << endl;
        }
    }
    return 0;
}
