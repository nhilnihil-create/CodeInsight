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
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define modd 998244353
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>

int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
 
       ll n,k;
       cin>>n>>k;
       ll ans =0;
       ll a[n];

       fori(0,n){
        cin>>a[i];
      
       }
       sort(a,a+n);
       fori(0,k)ans+=a[i];
        
        cout<<ans<<"\n";
      
 

     
 
return 0;
}     