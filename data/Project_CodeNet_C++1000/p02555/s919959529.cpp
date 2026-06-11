#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define drep(i, n) for(int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define dup(x,y) (((x)+(y)-1)/(y))
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

const ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
  ll ans = 1;
  while(n != 0){
    if(n&1) ans = ans*x % M;
    x = x*x % M;
    n = n >> 1;
  }
  return ans;
}

// 組み合わせ
ll comb(ll a, ll b){ 
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  ll tmp = ifac[a-b]* ifac[b] % M;
  return tmp * fac[a] % M;
}

int main() {
  int s;
  cin >> s;

    //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
  fac[0] = 1;
  ifac[0] = 1;
  for(ll i = 0; i<300000; i++){
    fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
    ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
  }

  ll ans = 0;
  rrep(i, 3000) {
    if (3*i > s) break;
    int res = s - 3*i;
    ans += comb(res+i-1, i-1);
    ans %= mod;
  }
  cout << ans << endl;
}