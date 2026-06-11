#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds; 
 
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

// typedef tree<pii,null_type,less<pii>,rb_tree_tag,
// tree_order_statistics_node_update>PBDS; 

vi prime;

void sieve(){
  vi p;
  p.resize(1001,1);
  prime.pb(2);

  for(int i=3;i<=1e3;i++)
    if(p[i]==1){
      prime.pb(i);
      for(int j=i+i;j<=1e3;j+=i)p[j]=0;
    }

  return;
}

ll res(ll num){
  if(num==1)return 1;

  // ll nn = sqrt(num);

  // ll ck=0;
  // if(nn*nn==num)ck=1;

  ll result = 1;

  for(auto x:prime)
    if(x*x>num)break;
    else if(num%x==0){
      ll cnt = 0;
      while(num%x==0){num=num/x;cnt++;}
      result *= (cnt+1) ;
    }

    if(num!=1)result*=2;

    
    return result;

  
}

int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  
   
    sieve();
    ll t;
    t=1;
    // cin>>t;
    while(t--){
     ll n;
     cin>>n;

    ll cnt = 0;

     for(int i=1;i<n;i++){
       ll num = n-i;
       cnt += res(num);
     }

     // cout<<res(45);
     cout<<cnt;

     

  






    }
      
     
      

      

    

    
return 0;
}     

