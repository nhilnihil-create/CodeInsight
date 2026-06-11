#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define rvisort(v) sort(v.begin(), v.end(), greater<int>());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
// #define int long long
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

class UnionFind{
  public:
  vector<int> Parent; 
  
  UnionFind(int N){
    Parent = vector<int>(N, -1);
  }
  
  int root(int A){
    if(Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }
  
  int size(int A){
    return -Parent[root(A)]; 
  }
  
  bool connect(int A, int B){
    A = root(A);
    B = root(B);
    if(A == B){
      return false;
    }
    
    if(size(A) < size(B)) swap(A, B);
    
    Parent[A] += Parent[B];
    Parent[B] = A;
    
    return true;
  }
};

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n,k; cin>>n>>k;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  set<ll> candidates;
  for(int i=1; i*i<=sum; i++){
    if(sum%i==0){
      candidates.insert(i);
      candidates.insert(sum/i);
    }
  }
  ll ans=1;
  for(ll x: candidates){
    ll need;
    vector<ll> r(n);
    rep(i,n)r[i]=a[i]%x;
    sort(r.begin(), r.end());
    ll B=0;
    rep(i,n)B+=x-r[i];
    ll A=0;
    need=1e18;
    rep(i,n){
      A+=r[i];
      B-=x-r[i];
      chmin(need,max(A,B));
    }
    if(need<=k) chmax(ans,x);
  }
  cout<<ans<<endl;
}
