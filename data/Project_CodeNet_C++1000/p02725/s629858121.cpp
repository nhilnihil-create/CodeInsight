#include <bits/stdc++.h>

// 円環の問題は切り開くと楽2周文とか
int main() {
  int k, n;
  int l_max = -1; // 家と家の距離の最大値
  std::cin >> k >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  
  for (int i = 0; i < n; i++)
    if (i == n-1) // 最初の家と最後の家の距離
      l_max = std::max(l_max, k+a[0]-a[i]);
    else
      l_max = std::max(l_max, a[i+1]-a[i]);

  std::cout << (k-l_max);
    

  return 0;
}