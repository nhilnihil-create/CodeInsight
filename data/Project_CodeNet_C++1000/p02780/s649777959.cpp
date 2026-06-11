#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,k;
  const int max_n = 2 * 1e5;
  cin >> n >> k;
  double p[max_n + 1];
  for(int i = 0; i < n; i++) cin >> p[i];

  // 各期待値を計算
  double res[max_n + 1];
  for(int i = 0; i < n; i++){
    res[i] = (1 + p[i]) / 2;
    // for(int j = 1; j <= p[i]; j++){
    //   res[i] += j;
    // }
    // res[i] /= p[i];
  }
  // 累積和計算
  double sum[max_n + 1];
  for(int i = 0; i < n; i++){
    if(i==0) sum[i] = res[i];
    else sum[i] = sum[i-1] + res[i];
  }
  // 最大値計算
  double ans = 0;
  double now = 0;
  for(int i = 0; i <= n - k; i++){
    if(i == 0) now = sum[k - 1];
    else now = sum[i + k - 1] - sum[i - 1];
    ans = max(ans, now);
  }
  cout << fixed << ans << endl;

  return 0;
}