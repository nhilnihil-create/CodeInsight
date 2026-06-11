#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define ull         unsigned long long int
#define ll          long long int
#define pb          push_back
#define pii         pair<int,int>
#define F           first
#define S           second
#define vi          vector<int>
#define vli          vector<ll>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define M_PI        3.14159265358979323846
#define mp          make_pair
#define sz(x)       (int)x.size()
#define matrix      vector<vector<ll>>
#define forn(i,a,b)  for(int i=a;i<b;i++)
#define eps 0.0000000001
#define all(a)      (a).begin(),(a).end()
#define ordered_set     tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> 
 
const long long INF = (long long) 1e11+1;
const long long mod = (long long) 998244353;
const long long hell = (long long) 1000000007;

ll power(ll x,ll y,ll m){
  ll res=1;
  while(y>0){
    if(y%2) res=(x%m*res%m)%m;
    x=(x%m*x%m)%m;    
    y=y/2;
  }
  
  return res%m;
}
 
ll modinv(ll x){
  return power(x,hell-2,1);
}

ll gcd(ll a,ll b){
    while(b!=0){
		ll t=b;
		b=a%t;
		a=t;
	}
	return a;
}    
    
void fastIO(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
} 
vi gr[200005];
ll ans,n;

void dfs(int v,int p){
    for(auto u:gr[v]){
        if(u!=p){
            dfs(u,v);
            ll x,y;
            x=u;
            y=v;
            
            if(x>y)
            swap(x,y);
            ans-=(x*(n-y+1));
        }
    }
}

void solve(){
    cin>>n;
    forn(i,1,n){
        int u,v;
        cin>>u>>v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    ans=0;
    forn(i,1,n+1){
        ans+=(i*(n-i+1));
    }
    dfs(1,-1);
    cout<<ans;
}    
    
int main(){
   fastIO();
   int test;
   //cin>>test;
   test=1;    
   
   while(test--)
   solve();
}