#include <bits/stdc++.h>

using namespace std;
struct Edge
{
    int to;
    Edge(int t) : to(t) {}
};

// Digraph
using Graph = vector<vector<Edge>>;

vector<int> topological_sort(const Graph &G)
{
    vector<int> order;
    int n = (int)G.size();
    vector<int> indegree(n);
    for (int e = 0; e < n; e++)
        for (auto &&ne : G[e])
            indegree[ne.to]++;

    queue<int> que;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int now = que.front();
        order.push_back(now);
        que.pop();
        for (auto &&e : G[now])
        {
            indegree[e.to]--;
            if (indegree[e.to] == 0)
                que.push(e.to);
        }
    }
    return order;
}

int main()
{
    int N;
    cin >> N;
    int graphsize = N * (N - 1) / 2;
    Graph dg(graphsize);

    auto toIndex = [N](int i, int j) {
        if (i > j)
            swap(i, j);
        return j - i - 1 + i * (2 * N - i - 1) / 2;
    };

    for (int i = 0; i < N; i++) // 0-indexed
    {
        int j;
        cin >> j;
        j--;
        int prevnode = toIndex(i, j);
        for (int l = 1; l <= N - 2; l++)
        {
            cin >> j;
            j--;
            dg[prevnode].push_back(Edge(toIndex(i, j)));
            prevnode = toIndex(i, j);
        }
    }

    auto top_order = topological_sort(dg);
    if (top_order.size() != graphsize)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> maxdist(graphsize, 0);
    for (size_t v = 0; v < graphsize; v++)
    {
        int tv = top_order[v];
        for (auto &&ne : dg[tv])
            maxdist[ne.to] = max(maxdist[ne.to], maxdist[tv] + 1);
    }

    int ans = maxdist[top_order.back()];
    cout << ans + 1 << endl;
    return 0;
}