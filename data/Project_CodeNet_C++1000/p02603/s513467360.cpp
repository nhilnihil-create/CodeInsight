#include <bits/stdc++.h>
using namespace std;

/*
dp.
株は安いときにたくさん買って, 高いときにたくさん売れば利益が最大化される.
買うときは全財産をつぎ込み, 売るときは持ち株を全て売る.
dp[x]はx日目に株の売却が終了した時点での所持金の最大値.
*/

int main() {
  long long N, A[85], dp[85];
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  dp[1] = 1000;
  for (int i = 2; i <= N; i++) {
    dp[i] = dp[i - 1];  // 今日のbase caseは昨日から何もしない場合
    for (int j = 1; j <= i - 1; j++) {
      long long stock = dp[j] / A[j];
      long long money = dp[j] + (A[i] - A[j]) * stock;  // 今日株を買って明日売った時点での所持金
      dp[i] = max(dp[i], money);  // 昨日から何もしない場合と, 株の売買をした場合を比較. 大きい方を選択
    }
  }
  cout << dp[N] << endl;
}