#include <iostream>
#include <vector>

int main() {
  using i64 = long long;

  int k, q;
  std::cin >> k >> q;
  std::vector<i64> d(k);
  for (i64 &e : d) {
    std::cin >> e;
  }

  for (int qi = 0; qi < q; qi += 1) {
    i64 n, x, m;
    std::cin >> n >> x >> m;
    // n 項の数列の境界は n-1 個
    n -= 1;

    // d の列は mod m で考える
    std::vector<i64> d2(k);
    for (int i = 0; i < k; i += 1) {
      d2[i] = d[i] % m;
    }

    // 加算される値の合計
    i64 sum = 0;
    // 0 が加算される回数
    i64 zero = 0;

    // 1 周期分を計算
    for (int i = 0; i < k; i += 1) {
      sum += d2[i];
      if (d2[i] == 0)
        zero += 1;
    }
    // floor(n / k) 周期なので掛ける
    sum *= n / k;
    zero *= n / k;

    // 1 周期に届かず残った部分を計算
    for (int i = 0; i < n % k; i += 1) {
      sum += d2[i];
      if (d2[i] == 0)
        zero += 1;
    }

    // m の倍数を跨ぐ回数
    i64 gt = (x + sum) / m - x / m;

    std::cout << n - gt - zero << std::endl;
  }
}