#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m,s,t;
vector<int> rad[100005];
int dp[100005];
int vdp[3][100005];

struct tor{
    int n,c,t;
    tor(int nn,int cc,int tt){
        n = nn;c = cc;t = tt;
    }
};
queue<tor> que;

void dfs(int now,int cnt,int toq)
{
    if(toq!=0)
    {
        if(vdp[toq][now]<=cnt) return;
        vdp[toq][now] = cnt;
        for(int i=0;i<rad[now].size();++i)
        {
            //dfs(rad[now][i],cnt,toq-1);
            que.push(tor(rad[now][i],cnt,toq-1));
        }
        return;
    }

    if(dp[now]<=cnt) return;
    dp[now] = cnt;
    for(int i=0;i<rad[now].size();++i)
    {
        //dfs(rad[now][i],cnt+1,2);
        que.push(tor(rad[now][i],cnt+1,2));
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    memset(dp,0x3f,sizeof(dp));
    memset(vdp,0x3f,sizeof(vdp));

    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&u,&v);
        rad[u].push_back(v);
    }

    scanf("%d%d",&s,&t);

    que.push(tor(s,0,0));
    while(!que.empty())
    {
        tor now = que.front();
        que.pop();
        dfs(now.n,now.c,now.t);
    }
    if(dp[t]==dp[n+1])printf("-1\n");
    else printf("%d\n",dp[t]);
    return 0;
}
