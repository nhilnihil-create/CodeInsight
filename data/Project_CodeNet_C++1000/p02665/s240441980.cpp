#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=1e5+5;
using namespace std;
ll l[N],r[N];
ll a[N];
int main()
{
    int n;cin>>n;
    for(int i=0;i<=n;i++) cin>>a[i];
    if(n==0)
    {
        if(a[0]==1) cout<<1<<endl;
        else cout<<-1<<endl;
        return 0;
    }
    //l[0]=1,r[0]=1;
    for(int i=n;i>=0;i--)
    {
        l[i]=(l[i+1]+1)/2+a[i];
        r[i]=r[i+1]+a[i];
    }
    if(l[0]!=1)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll ans=1,t=1;
    for(int i=1;i<=n;i++)
    {
        t-=a[i-1];
        t=min(r[i],t*2);
        ans+=t;
    }
    cout<<ans<<endl;
    return 0;
}
