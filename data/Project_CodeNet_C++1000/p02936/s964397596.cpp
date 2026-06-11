#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;

vector<vector<int>> graph(0, vector<int>());


void rOp(int child, int parent, vector<ll> & score){
    if(parent != -1) score[child] += score[parent];
    for (auto elem : graph[child])
    {
        if(elem == child) continue;
        rOp(elem, child, score);
    }
}

void dfs(int child, int parent, vector<ll> & score){
    for(auto elem : graph[child]){
        if(elem != parent){
            score[elem] += score[child];
            dfs(elem, child, score);
        }
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

    dfs(0, -1, ans);

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
