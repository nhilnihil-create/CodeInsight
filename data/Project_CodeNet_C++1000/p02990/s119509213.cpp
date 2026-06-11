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
  const ll maxn = 1e6 + 4;
  ll binpow(ll b,ll n){
  	 ll res = 1;
  	 while(n){
  	 	if(n%2){
  	 		res  = (res%MOD*b%MOD)%MOD;
  	 	}
  	 	b = (b%MOD*b%MOD)%MOD;
  	 	n/=2;
  	 }
  	 return res;
  }	
  ll cal(ll x,ll y){
  	 ll res = 1;
	 for(ll i =x;i>x-y;i--){
	 	res = (res%MOD*i%MOD)%MOD;
	 }  	
	 ll inv = 1;
	 for(ll i = 1;i <= y;i++){
	 	inv = (inv%MOD*i%MOD)%MOD;
	 }	
	 inv = binpow(inv,MOD-2);
	 return (res%MOD*inv%MOD)%MOD;
  }  	
  ll fact(ll x){
	ll res=1;
	for(int i=1;i<=x;i++){
		res = (res%MOD*i%MOD)%MOD;
	}
	return res;
  }
  void solve(){
	 int n,k;
	 cin >> n >> k;
	 ll ans=0;
	 for(ll i=1;i<=k;i++){
		ll sols = cal(k-1,i-1)%MOD;
		cout << ((sols%MOD*(cal(n-k+1,i))%MOD)%MOD) << '\n';
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
