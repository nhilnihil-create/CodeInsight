#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int X, Y;
  cin >> X >> Y;

  int ans = 0;

  if(X == 3){
    ans += 100000;
  }else if(X == 2){
    ans += 200000;
  }else if(X == 1){
    ans += 300000;
  }

  if(Y == 3){
    ans += 100000;
  }else if(Y == 2){
    ans += 200000;
  }else if(Y == 1){
    ans += 300000;
  }

  if(X == 1 && Y == 1){
    ans += 400000;
  }

  cout << ans << endl;

  return 0;
}
