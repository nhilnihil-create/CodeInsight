#include <bits/stdc++.h>
#include<algorithm>	
using namespace std;
#define ll long long 

const int MAX = 1000001;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

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
// 二項係数計算
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
  int x,y;
  cin >> x >> y;
  
  ll res = 0; 
  int flg = 0;
  if(2*x-y < 0 || (2*x-y)%3 != 0){
    flg = 1;  
  }
  
  if(2*y-x < 0 || (2*y-x)%3 != 0){
    flg = 1;  
  }
  int p,q;
  if(flg == 0){
    p = (2*x-y)/3;
    q = (2*y-x)/3; 
    COMinit();
    res = COM(p+q,p);  
  }
  cout << res;
  
}
