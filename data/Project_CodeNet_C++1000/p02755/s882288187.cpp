#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  double tax_a = 0.08, tax_b = 0.10;
  cin >> A >> B;
  
  int ans = -1, x = 0;
  while (1) {
    int a = x * tax_a; // 小数点切り捨て
    int b = x * tax_b;

    if (a == A && b == B) {
      ans = x;
      break;
    }
    if (b > B) break;
    x++;
  }
  cout << ans << endl;
}