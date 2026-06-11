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
       
       string s="";

       while(n){

        ll k = n/26;         // we are actually decreasing one digit from last
        ll rem = n%26;       // last digit 
        
        if(rem==0){          // considering the corner case of rem being = 26
          k--;
          s+='z';
        }
        else s+='a'+rem-1;
        n=k;
       }

       reverse(full(s));

       cout<<s;

      
 

     
 
return 0;
}     
