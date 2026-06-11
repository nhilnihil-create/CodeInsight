#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define ll              long long 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define Mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define vpii            vector<pair<int,int> >
#define all(x)          x.begin(),x.end()
#define sort(x)         sort(all(x))
#define umii            unordered_map<int,int>
#define lli             list<int>             
#define gcd(m,n)        __gcd(m,n)   
#define mib             map<int,bool>

#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define deb(...)
#endif

void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
 
//////////////////////////////code//////////////////////////////
ll power(ll x, ll y, ll p=Mod) 
{ 
    ll res = 1;    
  
    x = x % p; 
  
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 
  
     
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int32_t main()
{
  fast();
  
  int n,k;
  cin>>n>>k;
  
  int dp[k+1];
  
  for(int i=k;i>=1;i--)
  {
  	 int ans = (power(k/i,n));
  	 
  	 ans%=Mod;
  	 
  	 for(int j=2*i;j<=k;j+=i)
  	  ans = (ans%Mod - dp[j]%Mod + Mod)%Mod;
  	  
  	  dp[i]=ans;
  	 // deb(i,ans);
  }
  
  int sum=0;
  
  for(int i=1;i<=k;i++)
  {
   dp[i]=(i%Mod * dp[i]%Mod)%Mod;
   sum = (sum%Mod + dp[i]%Mod)%Mod;
  }
   
  cout<<sum;

}