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
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
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
  vi a(N);
  int sum=0;
  rep(i,N) {
    cin >> a[i];
    sum += a[i];
  }
  auto solve = [&](int k) -> bool {
    vi b(N);
    rep(i,N) {
      b[i]=a[i]%k;
    }
    sort(rng(b));
    reverse(rng(b));
    vi acc(N+1,0);
    rep(i,N) {
      acc[i+1]=acc[i]+b[i];
    }
    // [0,i)
    auto getL = [&](int i) {
      if(i<=0) return 0;
      return i*k-acc[i];
    };
    // [i,N)
    auto getR = [&](int i) {
      if(i>=N) return 0;
      return acc[N]-acc[i];
    };
    rep(d,N+1) {
      int lc = getL(d);
      int rc = getR(d);
      if(lc==rc&&lc<=K) return true;
    }

    return false;
  };
  int ans = 0;
  for(int k=1;k*k<=sum;k++) {
    if(sum%k!=0) continue;
    if(solve(k)) {
      chmax(ans,k);
    }
    if(solve(sum/k)) {
      chmax(ans,sum/k);
    }
  }
  cout << ans << endl;
  return 0;
}