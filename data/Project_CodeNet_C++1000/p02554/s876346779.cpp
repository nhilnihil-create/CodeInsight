#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define iof  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pi acos(-1)
int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,-1,1,-1,1};
const int mxn=1e5+7;
const int mod=1e9+7;
inline void normal(ll &a){a=((a%mod)+mod)%mod;}
inline ll modMul(ll a,ll b){normal(a);normal(b);return(a*b)%mod;}
inline ll modAdd(ll a,ll b){normal(a);normal(b);return (a+b)%mod;}
inline ll modSub(ll a,ll b){normal(a);normal(b);a-=b;normal(a);return a;}
inline ll modPow(ll b,ll a)
{
    ll r=1;
    while(a)
    {
        if(a&1)r=modMul(r,b);
        b=modMul(b,b);
        a>>=1;
    }
    return r;
}
int main()
{
    fast;
    ll n;
    cin>>n;
    ll ans=modSub(modAdd(modPow(10,n),modPow(8,n)),modMul(2,modPow(9,n)));
    cout<<ans<<endl;
}

