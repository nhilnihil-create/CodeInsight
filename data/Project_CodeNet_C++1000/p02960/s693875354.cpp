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
  string s;cin >> s;
  int n=s.size();
  vector<vector<mint>> v(n+5,vector<mint>(13));
  v[0][0]=1;
  rep(i,n){
    if(s[i]!='?'){
      int x=s[i]-'0';
      rep(j,13){
        v[i+1][(j*10+x)%13]+=v[i][j].x;
      }
    }
    else{
      rep(x,10){
        rep(j,13){
          v[i+1][(j*10+x)%13]+=v[i][j].x;
        }
      }
    }
  }
  cout << v[n][5].x << endl;
      
    
  
}
