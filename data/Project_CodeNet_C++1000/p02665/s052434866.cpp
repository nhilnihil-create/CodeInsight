#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn],r[maxn],l[maxn];
inline ll Pow2(int i){
    if(i<63) return 1ll<<i;
    else return 1e18;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<=n; i++) cin>>a[i];
    ll ans=0;
    l[n+1]=0,r[n+1]=0;
    for(int i=n; i>=0; --i)
    {
        l[i]=l[i+1]/2+l[i+1]%2;
        r[i]=r[i+1];
        l[i]+=a[i];
        r[i]+=a[i];
        if(l[i]>Pow2(i))
        {
            cout<<-1<<endl;
            return 0;
        }
        r[i]=min(r[i],Pow2(i));
    }
    for(int i=1; i<=n-1; i++)
    {
        ll x=l[i-1],y=r[i-1];
        x-=a[i-1];
        y-=a[i-1];
        y=2*y;
        l[i]=max(l[i],x);
        r[i]=min(r[i],y);
    }
    for(int i=0; i<=n; i++)
    {
        ans+=r[i];
    }
    cout<<ans<<endl;
    return 0;
}
