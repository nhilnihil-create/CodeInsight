#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

long long MOD = 1000000007;

int main(){
  long long N, K;
  cin >> N >> K;
  long long A[N];
  rep(i, N)
    cin >> A[i];
  // 入力終了

  long long ans = 0;
  
  // 自分自身の中にある転倒数の数
  long long inner = 0;
  rep(i, N-1){
    for(int j=i+1; j<N; j++){
      if(A[i] > A[j])
	inner = (inner+1)%MOD;
    }
  }

  // inner分をansに反映
  ans = (inner * K) % MOD;

  // A[i]より小さい数がA[]の中にいくつあるか
  long long cnt[2001] = {0};
  rep(i, N){
    rep(j, N){
      if(A[j] < A[i])
	cnt[ A[i] ]++;
    }
  }

  // 繰り返しでは，題意をみたすcnt[A[i]]回が(K-1)回繰り返される
  // i回目の繰り返しで，(i+1)回目以降の繰り返しにも関係する
  // (説明適当)
  rep(i, 2001){
    long long tmp = (K-1)*K/2%MOD;
    ans = (ans + (cnt[ i ]*tmp % MOD) ) % MOD;
  }

  // 解答
  cout << ans << endl;
  
  return 0;
}
