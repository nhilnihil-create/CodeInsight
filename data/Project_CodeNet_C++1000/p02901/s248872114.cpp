#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[10000];
int a[1005],b[1005],n,m;
int ans;

void dfs(int pos,int d,int cost)
{
    if(dp[d]!=-1&&cost>dp[d]) return;
    dp[d] = cost;
    if(pos>=m||d>=ans) return;
    dfs(pos+1,d|b[pos],cost+a[pos]);
    dfs(pos+1,d,cost);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&m);
    int ta,tb;
    ans = 1<<n;--ans;

    for(int i=0;i<m;++i){
        scanf("%d%d",a+i,&tb);
        for(int j=0;j<tb;++j){
            scanf("%d",&ta);
            b[i]|=(1<<(ta-1));
        }
    }
    dfs(0,0,0);
    printf("%d\n",dp[ans]);
    return 0;
}
