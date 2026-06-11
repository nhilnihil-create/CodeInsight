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

ll power(ll a, ll n) 
{ 
    if (n == 0) 
        return 1; 
    ll p = power(a, n / 2); 
    p = (p * p) ; 
    if (n & 1) 
        p = (p * a) ; 
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

    
 
       ll n;
       cin>>n;
       ll a[n];
       ll total_xor=0;
       fori(0,n){cin>>a[i];total_xor=total_xor^a[i];}

       fori(0,n)cout<<(a[i]^total_xor)<<" ";



      
 

     
 
return 0;
}     