#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const int mod=1e9+7;
char c[maxn];
ll pow(ll a,ll b)
{
    ll ans=1;
    a%=mod;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    cin>>c;
    int i,n=strlen(c);
    ll ans=1;
    for(i=n-1; i>=0; i--)
    {
        if(c[i]=='1')
        {
            ans=(ans<<1)%mod;
            ans=(ans+pow(3,(n-i-1)%mod))%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}







