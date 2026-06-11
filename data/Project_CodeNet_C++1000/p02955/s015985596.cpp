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
  
int main() {
  int N,K;
  cin >> N >> K;
  vi A(N);
  int ma = 0;
  int sum = 0;
  rep(i,N) {
    cin >> A[i];
    ma = max(ma,A[i]);
    sum += A[i];
  }
  int ans = 1;
  for(int k = 1;k * k <= sum;k++) {
    if(sum % k != 0) continue;
    vi d(N);
    rep(i,N) {
      d[i] = A[i] % k;
    }
    sort(rng(d));
    vi s(N+1,0);
    rep(i,N) {
      s[i+1] = s[i]+d[i];
    }
    bool ok = false;
    rep(i,N+1) {
      int a = s[i];
      int b = k * (N-i) - (s[N]-s[i]);
      if(a == b && a <= K) ok = true;
    }
    if(ok) {
      ans = max(ans,k);
    }
    int k2 = sum / k;
    d = vi(N);
    rep(i,N) {
      d[i] = A[i] % k2;
    }
    sort(rng(d));
    s = vi(N+1,0);
    rep(i,N) {
      s[i+1] = s[i]+d[i];
    }
    ok = false;
    rep(i,N+1) {
      int a = s[i];
      int b = k2 * (N-i) - (s[N]-s[i]);
      if(a == b && a <= K) ok = true;
    }
    if(ok) {
      ans = max(ans,k2);
    }
  }
  cout << ans << endl;
  return 0;
}