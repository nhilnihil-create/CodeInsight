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
  	ll res =1;
  	while(n){
  		if(n%2)
  			res = (res%MOD*b%MOD)%MOD;
  		n/=2;
  		b= (b%MOD*b%MOD)%MOD;
  	}
  	return res;
  }	

  void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll sum = binpow(2LL,n);
    ll cala=1;
    ll calb=1;
    ll mina=1,minb=1;
    for(ll i=1;i<=min(a,n-a);i++){
    	mina = (mina*i)%MOD;
    }
    for(ll i=1;i<=min(b,n-b);i++){
    	minb = (minb*i)%MOD;
    }    
    ll inva = binpow(mina,MOD-2);
    ll invb = binpow(minb,MOD-2);
    for(ll i=n;i>max(a,n-a);i--){
    	cala = (cala*i)%MOD;
    }
    for(ll i=n;i>max(b,n-b);i--){
    	calb = (calb*i)%MOD;
    }
    
    cala = (cala*inva)%MOD;
    calb = (calb*invb)%MOD;		
    sum = max(0LL,((sum - cala - calb-1)%MOD + MOD)%MOD);
    cout << sum;    
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
