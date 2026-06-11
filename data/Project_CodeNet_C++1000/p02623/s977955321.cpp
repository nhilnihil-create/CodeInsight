#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(long long i=0; i<n; i++)

int main(){
  long long N, M, K;
  cin >> N >> M >> K;
  long long tmp;
  long long A[N], B[M];
  rep(i, N)
    cin >> A[i];
  rep(i, M)
    cin >> B[i];
  // 入力終了

  // A[]とB[]の累積和
  long long cua[N+1]; cua[0] = 0;
  long long cub[M+1]; cub[0] = 0;
  rep(i, N)
    cua[i+1] = cua[i] + A[i];
  rep(i, M)
    cub[i+1] = cub[i] + B[i];

  long long ans = 0;

  // B[]をなめるindexと，その中で最適なbn
  int bn, bestbn = M;
  
  rep(an, N+1){
    // 累積和の性質上，bestbnから左に見ていけばOK
    bn = bestbn;

    // Kを下回るまでbnを減らしていく
    while(cua[an] + cub[bn] > K && bn>0)
      bn--;

    // bestの更新
    bestbn = bn;

    if(cua[an] + cub[bn] <= K){
      // 最大値の更新
      if(an + bn > ans)
	ans = an + bn;
    }
  }

  // 解答
  cout << ans << endl;
  
  return 0;
}
