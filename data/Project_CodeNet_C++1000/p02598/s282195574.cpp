//catgo
#include <iostream>
#define ll long long int
using namespace std;
ll n,k,a[5000000];
bool check(int m)
{
    ll sl=0;
    for(ll i=1; i<=n; ++i)
    {
        sl=sl+a[i]/m;
        if(a[i]%m==0) sl--;
    }
    return (sl<=k);
}
int main()
{
    //freopen("b.inp","r",stdin);
    cin>>n>>k;
    for(ll i=1; i<=n; ++i) cin>>a[i];
    ll d=1, c=a[1],g,m;
    for(ll i=2; i<=n; ++i) c=max(c,a[i]);
    while(d<=c)
    {
        g=(d+c)/2;
        if(check(g))
        {
            m=g;
            c=g-1;
        }
        else d=g+1;
       // cout<<m<<" "<<g<<endl;;
    }
    cout<<m;
    return 0;
}
