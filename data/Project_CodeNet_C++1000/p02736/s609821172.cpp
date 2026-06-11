// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
#define MAX 1100000
#define MOD 1000000007

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main(){
  init_io();
  ll n,x=0;
  bool is_o = false;
  vector<ll> v;
  string a;
  cin >> n >> a;
  COMinit();
  vector<ll> cp;
  for(char c:a){
    cp.push_back(c-'1');
  }
  for(int i=0;i<n-1;i++){
    v.push_back(abs(cp[i]-cp[i+1])); 
    if(v[i]==1){
      is_o = true;
    }
  }
  if(!is_o) for(int i=0;i<n;i++) v[i] /= 2;
  ll ans = 0;
  for(int i=0;i<n;i++){
    if(v[i]==1){
      if(((n-2)&i) == i){
        ans = !ans;
      }
    }
  }
  if(!is_o) ans *= 2;
  cout << ans << endl;
}

