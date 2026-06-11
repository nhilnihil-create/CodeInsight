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
ll MAX = 200000;
ll fac[200001];
ll inv[200001],finv[200001];
ll facc[200001];
ll invv[200001],finvv[200001];

void solve(){
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i  =2; i <= MAX; i++){
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
  ll n,k; cin >> n >> k;
  ll red = n-k;
  solve();
  for(int i = 1; i <= k; i++){
    cout << COM(n-k+1,i)*COM(k-1,i-1)%INF << endl;
  }
  return 0;
}
