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
      ll maxa=0,mini=1e15;
      ll maxa1 = -1e15,mini1=1e15;

      fori(0,n){
        ll x,y;
        cin>>x>>y;
        maxa = max(maxa,x+y);
        mini = min(mini,x+y);
        maxa1 = max(maxa1,x-y);
        mini1 = min(mini1,x-y);
      }

      cout<<max({maxa1-mini1,maxa-mini});





    }
     
      

      

    

    
return 0;
}     

