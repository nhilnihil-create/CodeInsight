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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vvi cnt(h, vi(w));
  rep(i, h) {
    vi done(w);
    rep(j, w){
      if (s[i][j] == '#') continue;
      if (done[j]) continue;
      int l = 0;
      while (j+l < w) {
        if (s[i][j+l] == '#') break;
        ++l;
      }
      rep(k, l) {
        cnt[i][j+k] += l;
        done[j+k] = l;
      }
    }
  }
  rep(j, w) {
    vi done(h);
    rep(i, h) {
      if (s[i][j] == '#') continue;
      if (done[i]) continue;
      int l = 0;
      while (i+l < h) {
        if (s[i+l][j] == '#') break;
        ++l;
      }
      rep(k, l) {
        cnt[i+k][j] += l;
        done[i+k] = l;
      }
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) {
    ans = max(ans, cnt[i][j]-1);
  }
  cout << ans << endl;
}