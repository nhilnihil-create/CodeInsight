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

map<ll, ll> prime_factor(ll n){
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++){
    while (n % i == 0){
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

bool is_prime(ll x){
    if(x<=1) return false;
    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
  ll n;
  cin >> n;
  map<ll, ll> pf = prime_factor(n);
  int ans = 0;
  for (auto z : pf) {
    ll a = z.first, b = z.second;
    if (!is_prime(a)) continue;
    int cnt = 1;
    while (b > 0) {
      if (b < cnt) break;
      b -= cnt;
      cnt++;
      ans++;
    }
  } 
  cout << ans << endl;
}