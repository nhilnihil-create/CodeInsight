#include <bits/stdc++.h>

int main() {
  int n, m, k; std::cin >> n >> m >> k;
  std::vector<long long> a(n);
  std::vector<long long> b(m);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];

  int ans = 0; // 最大冊数
  int time = 0; // 読書の所要時間
  int a_idx = 0; // 次に読むほんのidx(開いている)
  int b_idx = 0;  
  
  /* まずは机Aからのみ読む */
  while (a_idx < n && (time + a[a_idx]) <= k) {
    time += a[a_idx++];
    ans = a_idx;
  }
  /* 残り時間でBの本を読む */
  while (b_idx < m && (time + b[b_idx]) <= k) {
    time += b[b_idx++];
    ans = std::max(ans, a_idx+b_idx);
  } 

  /* Aの本を読むのを辞め，Bの本をどんどん読んでいく */
  while (a_idx--) {
    /* Aの本を読むのを辞める */
    time -= a[a_idx];
    // --ans;

    /* Bの本を読み進める */
    while (b_idx < m && (time + b[b_idx]) <= k) {
      time += b[b_idx++];
      // ans = std::max(ans, a_idx+b_idx);
    } 
    ans = std::max(ans, a_idx+b_idx);
  }


  std::cout << ans << std::endl;
  
  return 0;
}
