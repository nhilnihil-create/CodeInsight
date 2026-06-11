#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<endl
#define AA(i) cout<<i<<endl
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;

ll POW(ll n,ll m){
  long long pow = 1;
  while (m>0) {
    if ((m&1) == 1) pow = (pow*n)%MOD;
    m >>= 1;
    n = (n*n)%MOD;
  }
    return pow;
}

#define size 200010
long long fac[size],finv[size],inv[size];
void COMvec(ll N,int s){
  fac[0] = 1; fac[1] = N % MOD;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < s+1; i++){
    fac[i] = fac[i-1] * (N - i + 1) % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll COM(ll n,ll k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[k] * finv[k] % MOD;
}

int main(){
    ll n; cin>>n;
    int a,b; cin>>a>>b;
    COMvec(n,b);
    ll ans = (POW(2,n) - 1 - (COM(n,a) + COM(n,b)) % MOD  + MOD )% MOD;
    AA(ans);
    return 0;
}