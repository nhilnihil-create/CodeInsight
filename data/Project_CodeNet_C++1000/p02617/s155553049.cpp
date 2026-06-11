#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 1e18
#define MOD (long) (1e9 + 7)
#define double __float128

struct Node
{
    long k;
    long count;
    bool visited = false;
    vector<long> adj;
};

long solve(Node &r, auto &nodes, long n)
{
    r.count = r.k * (n - r.k + 1);
    long total = r.count;
    long count = 0;
    r.visited = true;
    for (auto &i : r.adj) {
        Node &u = nodes[i];
        if (u.visited) continue;
        total += solve(u, nodes, n);
        long x = min(r.k, u.k) * (n - max(r.k, u.k) + 1);
        total -= x;
    }
    return total;
}

int main()
{
    long n;
    cin >> n;

    vector<Node> nodes(n+1);
    for (long i = 1; i <= n; i++) {
        nodes[i].k = i;
    }
    for (long i = 0; i < n-1; i++) {
        long u, v;
        cin >> u >> v;
        nodes[u].adj.push_back(v);
        nodes[v].adj.push_back(u);
    }
    long ans = solve(nodes[1], nodes, n);
    printf("%lld\n", ans);
}
