#include <bits/stdc++.h>
using namespace std;
 int a,m,n,b,kt[100009],dem=0;
 vector<int> a1[100009];
void bfs(int a)
{
    kt[a]=dem;
    for (int i:a1[a])
    {
        if (kt[i]==0) bfs(i);
    }
}
int main()
{
//freopen("tplt.inp","r",stdin);
//freopen("tplt.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=100009;i++)
        kt[i]=0;
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b;
        a1[a].push_back(b);
        a1[b].push_back(a);
    }
    for (int i=1;i<=n;i++)
    {
        if (kt[i]==0) {dem++;bfs(i);}
    }
    cout<<dem-1;
    return 0;
}