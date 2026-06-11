#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

class Combi {
private:
  v(ll) fac, inv, finv;
  void init(int N) {
    fac[0] = fac[1] = 1; inv[1] = 1; finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  }
public:
  Combi(int N) : fac(N + 1), inv(N + 1), finv(N + 1) { init(N + 1); }
  ll Cmod(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }
  ll Pmod(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
  }
};
  
int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  if(s[0] == 'W' || s[2*N-1] == 'W') {
    cout << 0 << endl;
    return 0;
  }
  v(bool) isR(2*N,false);
  srep(i,1,2*N) {
    if(s[i] != s[i-1]) {
      isR[i] = isR[i-1];
    } else {
      isR[i] = !isR[i-1];
    }
  }
  int cnt = 0;
  rep(i,2*N) {
    if(isR[i]) cnt++;
  }
  if(cnt != N) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  int l = 0;
  rep(i,2*N) {
    if(isR[i]) {
      ans *= l;
      ans %= MOD;
      l--;
    } else {
      l++;
    }
  }
  Combi C = Combi(N);
  ans *= C.Pmod(N,N);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}