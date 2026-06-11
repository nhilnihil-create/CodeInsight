#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,k;
int f[100100];
vector<vector<int> >G;
void init()
{
    G.clear();
    G.resize(n+500);
    for(int i=1;i<=n+100;i++)  G[i].clear();
}
void dfs(int x,int fa)
{
    int now=1;
    if(fa!=-1)  now++;
    for(int &i:G[x])
    {
        if(i==fa)  continue;
        f[i]=k-now;now++;
        dfs(i,x);
    }
}
int main()
{
    cin>>n>>k;
    int x,y;
    init();
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);G[y].push_back(x);
    }
    f[1]=k;
    dfs(1,-1);
    long long ans=1;
    long long M=1000000007;
    for(int i=1;i<=n;i++)
    {
       // cout<<f[i]<<" ";
        ans=ans*f[i]%M;
    }
    cout<<ans<<endl;
    return 0;
}