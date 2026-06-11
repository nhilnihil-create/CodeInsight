#include <iostream>
#include <string>
#include <math.h>
#include<cstdlib>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int ans=0x3f3f3f3f;
int ar[22][22]={0};
int cr[22],dr[22];
long long int br[22]={0};
int n,m,x;
void dfs(int s,int sum)
{
    if(s==n+1)
    {
        for(int i=1;i<=m;i++) {if(dr[i]<x) return;}
        ans=min(ans,sum);
        return;
    }
    dfs(s+1,sum);
    for(int i=1;i<=m;i++)
    {
        dr[i]+=ar[s][i];
    }
    dfs(s+1,sum+cr[s]);
    for(int i=1;i<=m;i++)
    {
        dr[i]-=ar[s][i];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cr[i]);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&ar[i][j]);
            br[j]+=ar[i][j];
        }
    }
    int flag=0;
    for(int k=1;k<=m;k++)
    {
        if(br[k]<x) {printf("-1\n");flag=1;break;}
    }
    if(flag==0)
    {
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}

