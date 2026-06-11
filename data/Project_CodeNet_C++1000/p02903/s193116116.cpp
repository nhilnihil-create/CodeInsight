#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
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
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long ngcd(vector<long long> a) {
  long long res = a[0];
  for(int i=1; i<a.size() && res!=1; i++) res = gcd(a[i], res);
  return res;
}
long long nlcm(vector<long long> a){
  long long res = a[0];
  for(int i=1; i<a.size(); i++) res = lcm(a[i], res);
  return res;
}
bool is_prime(long long n) {
  if(n < 2) return false;
  for (long long i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}
int digsum(int n) {
  int res=0;
  while(n) res += n%10, n /= 10;
  return res;
}
int digcnt(int n){
  int res=0;
  while(n) res++, n /= 10;
  return res;
}
vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll h,w,a,b; cin>>h>>w>>a>>b;
  vector<vector<char>> ans(h,vector<char>(w,'0'));
  rep(i,h){
    if(i<b){
      rep(j,a) ans[i][j]='1';
    }else{
      irep(j,a,w) ans[i][j]='1';
    }
  }
  rep(i,h){
    rep(j,w) cout<<ans[i][j];
    cout<<endl;
  }
}