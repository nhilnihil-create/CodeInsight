#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define MOD 1000000007
#define mod9 1000000009
#define fast ios_base :: sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
#define ct ll t;cin>>t;while(t--)
#define bi begin()
#define ei end()
#define fi first 
#define se second  
#define foe(i,a,b) for(ll i=a;i<b;i++)
#define rfoe(i,a,b) for(ll i=a;i>=0;i--)
#define sz(s) s.size() 
#define mem(a,s) memset(a,s,sizeof(a)) 
#define all(v) v.bi,v.ei
#define MAX             8000000000000000064LL
#define MIN            -8000000000000000064LL  
// ll MOD; 
ll add(ll a, ll b){return (a%MOD + b%MOD + ((MAX)/MOD)*MOD)%MOD;}
ll sub(ll a, ll b){return (a%MOD - b%MOD + ((MAX)/MOD)*MOD)%MOD;}
ll mul(ll a, ll b){return ((a%MOD)*(b%MOD) + ((MAX)/MOD)*MOD)%MOD;}
ll fact[1000007]={0};
ll expo(ll x, ll y) {ll res=1;x=x%MOD;while(y>0){if(y&1)res=(1ll*res*x)%MOD;
y=y>>1;x=(1ll*x*x)%MOD;} return res;}
void facto() {fact[0]=1;fact[1]=1;for(ll i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%MOD;}
ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expo(fact[r],MOD-2)))%MOD; res=(res*(expo(fact[n-r],MOD-2)))%MOD; return res;}
ll npr(ll n,ll r) {facto(); ll res=1; res=fact[n]; res=(res*(expo(fact[n-r],MOD-2)))%MOD; return res; }
int const N=2e5+9;
ll const INF = 2e9+5;
ll n;
    
void solve()
{ 
   ll n;
   cin>>n;
   string s;
   cin>>s;
   if(n%2==1)
   {
    
            cout<<"No\n";
            return;
   }
   foe(i,0,n/2)
   {
        if(s[i]!=s[i+n/2])
        {
            cout<<"No\n";
            return;
        }
   }
   cout<<"Yes\n";

}
int main()
{
    fast
    // ct
        // freopen("input.txt", "r", stdin);
            // freopen("output.txt", "w", stdout);
    { 
        solve();
    }
}