#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;


int max_dimention(const vvi &tree)
{
    int r = 0;
    for (const vi &n : tree)
        r = max<int>(r, n.size());      
    return r;
}

pair<int,int> edge(int a, int b)
{
    if (a < b)
        return {a, b};
    else
        return {b, a};
}

void dfs(const vvi &tree, map<pair<int,int>,int> &edge_color, int K, int current, int parent)
{
    const vi &node = tree[current];
    for (int i = 0, c = 0; i < (int)node.size(); ++i)
    {
        int next = node[i];
        if (next == parent) continue;
        if (parent >= 0 && c == edge_color[edge(current, parent)]) ++c;

        edge_color[edge(current, next)] = c++;
        dfs(tree, edge_color, K, next, current);
    }
}

int main()
{
    int N;
    cin >> N;

    vvi tree(N);
    vector<pair<int,int>> edges(N-1);
    map<pair<int,int>,int> edge_color;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;

        tree[a].push_back(b);
        tree[b].push_back(a);

        auto e = edge(a,b);
        edges[i] = e;
        edge_color[e] = -1;
    }

    int K = max_dimention(tree);
    dfs(tree, edge_color, K, 0, -1);

    cout << K << endl;
    for (auto e : edges)
        cout << (edge_color[e] + 1) << endl;
}