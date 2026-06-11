  #pragma GCC optimize("Ofast")
  #pragma GCC target("avx,avx2,fma")
  #include <bits/stdc++.h>
  using namespace std;
  //---------------------------------//
  void __print(int x) {cerr << x;}
  void __print(long x) {cerr << x;}
  void __print(long long x) {cerr << x;}
  void __print(unsigned x) {cerr << x;}
  void __print(unsigned long x) {cerr << x;}
  void __print(unsigned long long x) {cerr << x;}
  void __print(float x) {cerr << x;}
  void __print(double x) {cerr << x;}
  void __print(long double x) {cerr << x;}
  void __print(char x) {cerr << '\'' << x << '\'';}
  void __print(const char *x) {cerr << '\"' << x << '\"';}
  void __print(const string &x) {cerr << '\"' << x << '\"';}
  void __print(bool x) {cerr << (x ? "true" : "false");}

  template<typename T, typename V>
  void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
  template<typename T>
  void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
  void _print() {cerr << "]\n";}
  template <typename T, typename... V>
  void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
  #ifndef ONLINE_JUDGE
  #define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
  #else
  #define deb(x...)
  #endif
 //------------------------------//

  typedef long long int ll;
  typedef pair<int,int> pi;
  typedef pair<ll,ll> pll;
  typedef vector<int> vi;
  typedef vector<ll> vll;
  typedef vector<pi> vpi;
  typedef vector<pll> vpll;

  #define  ff           first
  #define  ss           second
  #define  pb           push_back
  #define  IOS          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define  all(x)       (x).begin(), (x).end()
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 1e6 + 4;
  vll p(maxn),c(maxn);
  ll f;
  ll n,k;
  vector<ll> get(int i){
       vector<bool> vis(n,0);        
       vll start_here;
       int pos = i;
       while(!vis[pos]){
         vis[pos]=1;
         if(start_here.size()==0){
            start_here.pb(0);
            f = c[pos];
         }
         else{
           start_here.pb(start_here.back()+c[pos]);
         }
         pos = p[pos]-1;
       }
    return start_here;
  }
  void solve(){
     cin >> n >> k;
     ll ans=INT_MIN;
     rep(i,0,n)cin >> p[i];
     rep(i,0,n)cin >> c[i];
     rep(i,0,n){
       vll sh =get(i);
       int sz = sh.size();
       ll l = sh[sz-1],tmpans=-INF;
         if(k >= sz){
           ll a=-1e18,b=-1e18;
           for(int j=1;j<sz;j++){
             if(j<=k%sz)b=max(b,sh[j]);
             a = max(a,sh[j]);
           }
           if(a==-1e18)a=0;
           if(b==-1e18)b=0;
           ll o = max((k/sz)*(l+f)+b,max(0LL,k/sz-1)*(l+f)+a);
           tmpans = max({tmpans,o,a});
         }
         else{
           ll b = -1e18;
           for(int j=1;j<=k;j++){
             b = max(b,sh[j]);
           }
           tmpans = max(tmpans,b);
         }
       ans = max(ans,tmpans);
     }
     cout << ans;
  }

  int main(){
    IOS
    	solve();
    //cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow