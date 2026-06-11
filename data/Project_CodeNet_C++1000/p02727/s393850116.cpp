#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
typedef long long ll;
ll ans,a[N],b[N],c[N],d[N*4],A[N],B[N],C[N],x,y,q,w,e;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    cin>>x>>y>>q>>w>>e;
    for(int i=1;i<=q;i++)
        cin>>a[i];
    sort(a+1,a+q+1,cmp);
    int cnt=0;
    for(int i=1;i<=x;i++)
    {
        d[++cnt]=a[i];
    }
     for(int i=1;i<=w;i++)
        cin>>b[i];
    sort(b+1,b+w+1,cmp);
    for(int i=1;i<=y;i++)
    {
        d[++cnt]=b[i];
    }
    for(int i=1;i<=e;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=x+y+e;i++)
    {
        d[++cnt]=c[i];
    }
    sort(d+1,d+x+y+e+1,cmp);
    for(int i=1;i<=x+y;i++)
    {
       ans+=d[i];
    }
        cout<<ans<<endl;

}