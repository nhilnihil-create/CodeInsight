#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define drep(i, n) for(int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Mod int
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
//


int main() {
  int n, k;
  cin >> n >> k;
  vi p(n), c(n);
  rep(i, n) {int np; cin >> np; p[i] = np-1;}
  rep(i, n) cin >> c[i];
  vvi d;
  vi used(n, 0);
  rep(i, n) {
    if (used[i]) continue;
    vi nd;
    used[i] = 1;
    int ni = p[i];
    nd.push_back(i);
    while(!used[ni]) {
      used[ni] = 1;
      nd.push_back(ni);
      ni = p[ni];
    }
    d.push_back(nd);
  }
  ll ans = -LINF;
  rep(i, d.size()) {
    rep(j, d[i].size()) {
      vi dd = d[i];
      rep(k, d[i].size()) dd.push_back(d[i][k]);
      vi md;
      for (int m = j; m < j + d[i].size(); ++m) md.push_back(dd[m]);
      int l = md.size();
      ll tot = 0;
      rep(i, l) tot += c[md[i]];
      ll t = 0;
      rep(i, l) {
        t += c[md[i]];
        if (i+1 > k) break;
        ll now = t;
        if (tot > 0) {
          ll e = (k-(i+1))/l;
          now += tot*e;
        }
        ans = max(ans, now);
      }
    }
  }
  cout << ans << endl;
}