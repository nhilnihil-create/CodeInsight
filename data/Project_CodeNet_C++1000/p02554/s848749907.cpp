#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb      push_back
#define all(v)  v.begin(),v.end()
#define see(x)  cout<<#x<<" : "<<(x)<<endl;
#define ya      cout<<"YES"<<endl;
#define no      cout<<"NO"<<endl;
#define ff      first
#define sc      second
#define inf     999999999
typedef long long ll;
typedef pair<ll,ll> pii;

const int mod=1e9+7;

int main()
{

    ll n,i,ans=0;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        exit(0);
    }
    ll a=1,b=1,c=1;
    
    for(i=1;i<=n;i++)
    {
        a=(a*10)%mod;
        c=(c*9)%mod;
        b=(b*8)%mod;
    }
    
    c=(c*2)%mod;
    
    cout<<((a-c+mod)%mod+b%mod+mod)%mod<<endl;

    return 0;
}

