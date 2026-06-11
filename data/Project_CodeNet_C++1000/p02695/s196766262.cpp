#include <bits/stdc++.h>

using namespace std;
int n,m,q;
struct Str{
    int a,b,c,d;
};
Str a[51];
int x[51];
int ans;
void update()
{
    int sum  =0;
    for(int i=1;i<=q;i++)
    {
        if(x[a[i].b] - x[a[i].a] == a[i].c)
            sum+=a[i].d;
    }
    ans=max(ans,sum);
}
void trys(int i)
{
    for(int j=x[i-1];j<=m;j++)
    {
        x[i] = j;
        if(i==n)
        {
            update();
        }
        else
            trys(i+1);
    }
}
int main()
{
    cin>>n>>m>>q;
    x[0] = 1;
    for(int i=1;i<=q;i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
    }
    trys(1);
    cout<<ans;
    return 0;
}
