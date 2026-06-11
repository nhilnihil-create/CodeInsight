#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  mint ans=1;
  int r=0,b=0,g=0;
  rep(i,n){
    int col=0;
    int x=v[i];
    if(r==x) col++;
    if(b==x) col++;
    if(g==x) col++;
    ans*=col;
    if(col==0) break;
    if(r==x){
      r++;
      continue;
    }
    if(g==x){
      g++;
      continue;
    }
    if(b==x){
      b++;
      continue;
    }
  }
  cout << ans.x << endl;
    
    
}