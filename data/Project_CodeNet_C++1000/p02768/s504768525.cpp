#include <iostream>

using namespace std;

long long MOD = 1000000007;

//n^rを計算
long long mod_power(long long n, long long r){
  long long ans = 1;
  //rの二進展開を考える
  while(r>0){
    //rの右端ビットが立っていればansの更新
    if(r & 1 == 1)
      ans = ans * n % MOD;
    //繰り返し二乗法
    n = n * n % MOD;
    //rの1ビットシフト
    r >>= 1;
  }
  return ans;
}

//nCrを計算
long long mod_comb(long long n, long long r){
  long long den = 1, num = 1; //分母，分子
  long long ans;
  
  //分母はr!
  for(long long i=1; i<=r; i++)
    den = den * i % MOD;

  //分子は頑張る
  for(long long i=0; i<r; i++)
    num = num * (n-i) % MOD;

  //フェルマーの小定理を使う(a^p-2)
  ans = num * mod_power(den, MOD-2) % MOD;
  
  return ans;
}


int main(){
  long long N, a, b;
  cin >> N >> a >> b;
  //入力終わり

  //二項定理の利用

  //1種類も選ばないときをひいておく
  long long ans = mod_power(2, N)-1;

  //NCaとNCbもひく
  ans = (ans + MOD - mod_comb(N, a) ) % MOD;
  ans = (ans + MOD - mod_comb(N, b) ) % MOD;

  cout << ans << endl;
  
  return 0;
}
