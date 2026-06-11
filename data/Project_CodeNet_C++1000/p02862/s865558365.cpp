#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

ll INF = 1000000007;
ll fac[10000000];
ll inv[10000000],finv[10000000];

void solve(ll n, ll m){
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i  =2; i <= n+m; i++){
    fac[i] = fac[i-1] * i %INF;
    inv[i] =INF - inv[INF%i]*(INF/i)%INF;
    finv[i] = finv[i-1]*inv[i]%INF;
  }
}

ll COM(ll n, ll k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%INF)%INF;
}

int main(void){
  ll X,Y; cin >> X >> Y;
  ll n = (2*X-Y)/3, m = (2*Y-X)/3;
  if((X+Y)%3 != 0){
    cout << 0 << endl;
    return 0;
  }
  if(n < 0 || m < 0){
    cout << 0 << endl;
    return 0;
  }
  solve(n,m);
  cout << COM(n+m,m) << endl;
  return 0;
}
