#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>
#define que pair<pii,pii>

int N, M, Q;
que q[60];
int mem[20];

int DFS(int n, int v)
{
    if(n == N)
    {
        int ret = 0;
        rep(i, Q)
        {
            que now = q[i];
            pii lr = now.first;
            pii d = now.second;
            if(mem[lr.second] - mem[lr.first] == d.first)ret += d.second;
        }
        return ret;
    }
    int ret = 0;
    for(int i = v; i <= M; i++)
    {
        mem[n] = i;
        ret = max(DFS(n + 1, i), ret);
    }
    return ret;
}

signed main()
{
    cin >> N >> M >> Q;
    rep(i, Q)
    {
        int l, r, d, v;
        cin >> l >> r >> d >> v;
        q[i] = {{l - 1, r - 1}, {d, v}};
    }
    cout << DFS(0, 1) << endl;
    return 0;
}


