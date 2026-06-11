#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

//ここから編集

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
 
// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
int N, M, Q; 
ll ans = 0;


ll a[55],b[55],c[55],d[55];
void dfs(vector<int> v){
  if(v.size() == N){
    ll tmp = 0;
    for(int i=0; i<Q; i++){
      if(v[b[i]] - v[a[i]] == c[i]){
        tmp += d[i];
      }
    }
    ans = max(ans, tmp);
    return;
  }

  for(int i=v[v.size()-1]; i<=M; i++){
    v.push_back(i);
    dfs(v);
    v.pop_back();
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(5);
  
  cin >> N >>M >> Q;
  REP(i,Q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }

  vector<int> v;
  for(int i=1; i<=M; i++){
    v.push_back(i);
    dfs(v);
    v.pop_back();
  }
  cout << ans << endl;
  return 0;
}
