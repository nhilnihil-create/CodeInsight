#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N, Q;
vector<int> G[200010];
int ans[200010];

void DFS(int v, int p=0)
{
    if(p != 0)ans[v] += ans[p];
    for(auto u : G[v])if(u != p)DFS(u, v);
}

signed main()
{
    cin >> N >> Q;
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, Q)
    {
        int p, x;
        cin >> p >> x;
        ans[p] += x;
    }

    DFS(1);

    for(int i = 1; i <= N; i++)
    {
        if(i - 1)cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
