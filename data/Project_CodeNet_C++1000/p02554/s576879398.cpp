#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vpi vector<pii>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>
#define mm 998244353

ll power(ll a, ll n,ll m) 
{ 
    if (n == 0) 
        return 1; 
    ll p = power(a, n / 2,m) % m; 
    p = (p * p) % m; 
    if (n & 1) 
        p = (p * a) % m; 
    return p; 
} 


int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  
 
    ll t;
    t=1;
    // cin>>t;
    while(t--){
      ll n;
      cin>>n;
      if(n==1)cout<<0;
      else{
        ll ans1 = power(10,n,mod);
        ll ans2 = power(8,n,mod);
        ll ans3 = power(9,n,mod);

       
        ans1 = (ans1-ans3+mod)%mod;
        ans1 = (ans1-ans3+mod)%mod;
         ans1 = (ans1+ans2+mod)%mod;
        
        cout<<ans1;
      }





    }
     
      

      

    

    
return 0;
}     

