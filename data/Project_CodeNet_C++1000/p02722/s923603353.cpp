#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=1e2+5;
using namespace std;
int main()
{
    ll n;cin>>n;
    ll ans=2;
    if(n==2) ans=1;
    for(ll i=2;i*i<=n;i++)
    {
        ll m=n;
        while(m>=i)
        {
            m%i?m%=i:m/=i;
        }
        if(m==1) ans++;
        if((n-1)%i==0&&i*i!=(n-1)) ans++;
    }
    cout<<ans;
    return 0;
}
