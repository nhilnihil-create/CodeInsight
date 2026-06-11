#include <bits/stdc++.h>

int main() {
  int money;
  int p = 0;  // 嬉しさ
  std::cin >> money;
  
  p += (money / 500 * 1000); // 500円の嬉しさ
  money %= 500;   // 残金の更新
  p += (money / 5 * 5); // 5円の嬉しさ

  std::cout << p;

  return 0;

}