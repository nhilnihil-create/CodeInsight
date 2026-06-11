#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>G;
vector<int>P;
vector<int>ans;

void dfs(int v, int sum)
{
    ans[v] += sum + 1;
    for(auto nv: G[v])
    {
        if(ans[nv] != -1) continue;
        dfs(nv,sum + P[nv]);
    }
}

int main()
{
    int N,Q;
    cin >> N >> Q;
    G.resize(N);
    for(int i = 0; i < N - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    P.assign(N,0);
    for(int i = 0; i < Q; i++)
    {
        int p,x;
        cin >> p >> x;
        p--;
        P[p] += x;
    }
    ans.assign(N,-1);
    dfs(0,P[0]);
    for(int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}