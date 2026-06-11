  #include <bits/stdc++.h>
  using namespace std;

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
  #define  D(x)         cout << #x << " - " << x << endl;
  #define  D2(x)        cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]" << endl;
  #define  all(x)       (x).begin(), (x).end()
  #define  D2p(x)       cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << endl;
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 2e5 + 4;
  vi adj[maxn];
  vll counter(maxn);
  void dfs(int src,int parcount,int par=-1){
  	  counter[src] += parcount;
  	  for(int x:adj[src]){
			if(par == x)continue;
			else{
				dfs(x,counter[src],src);
			}
  	  }
  }	
  void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    } 
    while(q--){
    	int p,x;
    	cin >> p >> x;
    	counter[p]+=x;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
    	cout << counter[i] << ' ';
    }	
  }

  int main(){
    IOS
    solve();
    cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
