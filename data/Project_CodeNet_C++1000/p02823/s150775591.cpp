#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b) swap(a, b);

  ll dist_ab = b - a;
  if (!(dist_ab & 1)) {  // 距離偶数のときはお互いに近づけばOK
    cout << dist_ab / 2 << endl;
    return 0;
  }

  // 距離奇数のときは、端に近い方が端で1勝か1敗して偶数に調整する
  ll dist_1a = a - 1;
  ll dist_bn = n - b;
  // 端への移動 + 偶数調整 + 互いに接近
  cout << min(dist_1a, dist_bn) + 1 + (b - a - 1) / 2 << endl;
  return 0;
}
