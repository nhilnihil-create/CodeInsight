#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
#include<iomanip>
#define ll long long
using namespace std;
#define MAXN 100005
int fa[MAXN],rankk[MAXN];

int find(int x)
{
    if(x==fa[x])
        return x;
    else
        return x = find(fa[x]);
}
void init(int n)
{
    for(int i=0; i<=n; ++i)
    {
        fa[i] = i;
        rankk[i] = 1;
    }
}
void merge(int i,int j)
{
    int x = find(i),y = find(j);
    if(rankk[x]<=rankk[y])
        fa[x] = y;
    else
        fa[y] = x;
    if(rankk[x]==rankk[y] && x!=y)
        rankk[y]++;
}
int n,m;
int main()
{
    cin>>n>>m;
    init(n);
    for(int i=0; i<m; ++i){
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    int sum = 0;
    for(int i=1; i<=n; ++i){
        if(fa[i]==i)
            sum++;
    }
    cout<<sum-1<<endl;
    return 0;
}

