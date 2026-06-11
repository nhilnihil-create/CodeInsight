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

vi dp;

ll fun(ll i){
  if(i==0)return 1;

  if(dp[i]!=-1)return dp[i];
  ll res = 0;

  for(int j=3;j<=2000;j++)
  if(j>i)break;
  else res=(res+fun(i-j))%mod;

  return dp[i]=res;
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
      dp.resize(n+1,-1);

      cout<<fun(n);





    }
     
      

      

    

    
return 0;
}     

