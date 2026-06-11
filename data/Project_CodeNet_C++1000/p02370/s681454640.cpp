#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

template <typename T>
struct edge
{
    int src, to;
    T cost;
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;

template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
using UnweightedGraph = vector<vector<T>>;

template <typename T>
using Matrix = vector<vector<T>>;

// Tarjan's algorithm
// G is a DAG.

void visit(const UnweightedGraph<int> &G, int u, vector<bool> &used, vector<int> &ans)
{
    if (used[u] == false)
    {
        used[u] = true;
        for (auto &v : G[u])
        {
            visit(G, v, used, ans);
        }
        ans.emplace_back(u);
    }
}

vector<int> topological_sort(const UnweightedGraph<int> &G)
{
    const int N = G.size();

    vector<bool> used(N, false);
    vector<int> ans;
    for (int u = 0; u < N; u++)
    {
        visit(G, u, used, ans);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    UnweightedGraph<int> G(V);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    auto d = topological_sort(G);

    for (int i = 0; i < V; i++)
    {
        cout << d[i] << endl;
    }
}
