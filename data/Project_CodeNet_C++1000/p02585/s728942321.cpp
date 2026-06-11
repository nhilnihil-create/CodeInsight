#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl; 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

const int N = 5050;
int p[N],c[N];
int val[N];
int32_t main(){
  fastio;
  int n,k;
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    cin >> p[i];
  }
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }
  ll best=-1e18;
  for(int st=1;st<=n;st++){
    // start here:
    ll cic=0;
    int cur = p[st];
    int t = 0;
    while(cur!=st){
      cic+=c[cur];
      val[++t] = cic;
      cur = p[cur];
    }
    cic+=c[cur];
    val[++t] = cic;
    best = max(best,val[1]);
    for(int i=1;i<=t;i++){
      ll falta = max(0LL,(1ll * ((k - i)/t) * val[t]));
   //   cout << i<<" "<<st<<" "<<val[i]<<" "<<cic<<" "<<(k-i)/x << endl;
      ll res = val[i] + falta;
      if(i > k)break;
      best = max(best,res);
    }

  }
  cout << best << endl;
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}