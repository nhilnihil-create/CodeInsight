#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int f[N];
int n;
int getf(int x)
{
    return f[x]==x?x:f[x]=getf(f[x]);
}
void merge(int x,int y)
{
    int fx=getf(x);
    int fy=getf(y);
    if(fx!=fy)
    {
        f[fy]=fx;
        return ;
    }
}
void init()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
}
set<int>s;
int main()
{
    int m;
    int x,y;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        s.insert(getf(i));
    }
    printf("%d",s.size()-1);
}
