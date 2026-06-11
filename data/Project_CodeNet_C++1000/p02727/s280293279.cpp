#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;



signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  priority_queue<ll> A,B,C;
  rep(i,a){
    ll t; cin>>t; A.emplace(t);
  }
  rep(i,b){
    ll t; cin>>t; B.emplace(t);
  }
  rep(i,c){
    ll t; cin>>t; C.emplace(t);
  }
  
  priority_queue<ll, vector<ll>, greater<ll>> AA, BB;
  
  while(x--){
    AA.emplace(A.top()); A.pop();
  }
  while(y--){
    BB.emplace(B.top()); B.pop();
  }
  
  while(!C.empty() && (C.top()>AA.top() || C.top()>BB.top())){
    if(AA.top()<BB.top()){
      AA.pop(); AA.emplace(C.top()); C.pop();
    }else{
      BB.pop(); BB.emplace(C.top()); C.pop();
    }
  }
  
  ll ans=0;
  while(!AA.empty()){
    ans+=AA.top(); AA.pop();
  }
  while(!BB.empty()){
    ans+=BB.top(); BB.pop();
  }
  
  
  cout<<ans<<endl;
  
}