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

ll njo(ll a, ll n, ll mod){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

void COMinit(){
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i  =2; i <= MAX; i++){
    inv[i] =INF - inv[INF%i]*(INF/i)%INF;
    finv[i] = finv[i-1]*inv[i]%INF;
  }
}

void faccul(ll n){
  fac[1] = n%INF;
  for(int i = 2; i <= MAX; i++){
    fac[i] = fac[i-1]*(n-i+1)%INF;
  }
}

ll COM(ll n, ll k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[k]*finv[k]%INF;
}

int main(void){
  ll n,a,b; cin >> n >> a >> b;
  ll ans = njo(2,n,INF)-1;
  COMinit();
  faccul(n);
  ans -= COM(n,a) + COM(n,b);
  while(1){
    if(ans < 0){
      ans += INF;
    }
    else break;
  }
  cout << ans << endl;
  return 0;
}
