// https://atcoder.jp/contests/abc138/tasks/abc138
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N), b(N);
    for (int i = 0; i < N - 1; ++i) cin >> a[i] >> b[i], --a[i], --b[i];
    vector<int> p(Q), x(Q);
    for (int i = 0; i < Q; ++i) cin >> p[i] >> x[i], --p[i];

    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i)
    {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<int> parent(N, -1); // 頂点 i の親
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for (const auto& nv : G[v])
        {
            if (parent[v] == nv) continue;
            parent[nv] = v;
            que.push(nv);
        }
    }
    vector<int> res(N, 0);
    for (int j = 0; j < Q; ++j)
    {
        res[p[j]] += x[j];
    }

    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for (const auto& nv : G[v])
        {
            if (parent[v] == nv) continue;
            res[nv] += res[v];
            que.push(nv);
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << res[i];
        if (i != N - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}