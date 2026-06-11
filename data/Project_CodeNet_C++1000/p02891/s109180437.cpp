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
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  bool ok = true;
  rep(i, n) if (s[0] != s[i]) ok = false;
  if (ok) {
    ll ans = (ll)n*k/2;
    cout << ans << endl;
    return 0;
  }

  int x = 0;
  int cnt = 1;
  char now = s[0];
  for (int i = 1; i <= n-1; i++) {
    if (s[i] == now) cnt++;
    else {
      x += cnt/2;
      now = s[i];
      cnt = 1;
    }
  }
  x += cnt/2;
  ll ans = 0;
  ans += (ll)x * k;
  if (s[0] == s[n-1]) {
    int l = 1, r = 1; 
    char nl = s[0], nr = s[n-1];
    for (int i = 1; i < n; i++) {
      if (s[i] == nl) l++;
      else break;
    }
    for (int i = n-2; i >= 0; i--) {
      if (s[i] == nr) r++;
      else break;
    }
    if ((l+r)%2 == 0) ans += k-1;
  }
  cout << ans << endl;
}