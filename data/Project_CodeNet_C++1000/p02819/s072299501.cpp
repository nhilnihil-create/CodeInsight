#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

bool IsPrime(int num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;  // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main(void) {
  int x;
  cin >> x;
  bool flg = false;
  while (true) {
    flg = IsPrime(x);
    if (flg) break;
    x++;
  }
  cout << x << endl;
  return 0;
}