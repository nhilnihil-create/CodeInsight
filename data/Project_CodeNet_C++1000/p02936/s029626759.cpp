#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;

vector<vector<int>> graph(0, vector<int>());


void rOp(int v, int p, vector<ll> & score){
    if(p != -1) score[v] += score[p];
    for (auto elem : graph[v])
    {
        if(elem == p) continue;
        rOp(elem, v, score);
    }
}

int main(void)
{
    cin >> N >> Q;
    graph.resize(N);
    vector<ll> ans(N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < Q; i++)
    {
        int p, x;
        cin >> p >> x;
        ans[p-1] += (ll) x;
    }

    rOp(0, -1, ans);

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
