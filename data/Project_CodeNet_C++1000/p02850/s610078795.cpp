#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> G[N];
    vector<pair<int, int>> vp;
    map<pair<int, int>, int> I;
    for (int i = 1; i < N; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vp.push_back(make_pair(a, b));
    }

    vector<int> seen(N, 0);
    vector<int> cs(N, 0);
    queue<int> que;
    int K = 0;
    seen[0] = 1;
    que.push(0);
    while (!que.empty())
    {
        int v = que.front(); que.pop();
        if(K < (int)G[v].size()) K = G[v].size();
        int cur = 1;
        for (auto next_v : G[v])
        {
            if(seen[next_v]) continue;
            if(cur == cs[v]) cur++;
            seen[next_v] = 1;
            cs[next_v] = I[make_pair(v, next_v)] = I[make_pair(next_v, v)] = cur++;
            que.push(next_v);
        }
    }

    cout << K << endl;
    for (auto p : vp)
    {
        cout << I[p] << endl;
    }

    return 0;
}