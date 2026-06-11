#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repn(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define sz(v) (ll)v.size()
#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
using namespace std;

ll MOD=1e9+7;
ll g,h,l;
const ll N=100005, inf=1e9+5;

ll add(ll a,ll b); ll mul(ll a,ll b); ll binpo(ll a,ll b);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;cin>>n;
    ll n2 = n-1;
    ll cnt=0;
    for(ll i = 2; i*i<=n2; i++){
        if(n2%i==0){
            // cout<<i<<" "<<n2/i<<endl;
            cnt+=2;
        }
        if(i*i==n2){
            cnt--;
        }
    }
    cnt+=2;
    if(n==2)cnt--;
    for(ll i=2;i*i<=n;i++){
        ll temp = n;
        if(i*i==n){
            cnt++;
            continue;
        }
        if(n%i==0){
            while(temp%i==0){
                temp/=i;
            }
            if(temp%i==1){
                cnt++;
                // cout<<i<<endl;
            }
        }
        temp =n ;
        ll i2 = temp/i;
        if(n%i2==0){
            while(temp%i2==0){
                temp/=i2;
            }
            if(temp%i2==1){
                cnt++;
                // cout<<i2<<endl;
            }
        }
    }
    cout<<cnt;
}

ll add(ll a,ll b)
{
    return (a%MOD+b%MOD)%MOD ;
}
ll mul(ll a,ll b)
{
    return (a* 1ll *b)%MOD ;
}
ll binpo(ll a,ll b)
{
    int ans = 1 ;
    while(b)
    {
        if( b % 2 != 0)
        {
            ans = mul(ans,a);
        }
        a = mul(a,a);
        b = b/2;
    }
    return ans;
}