#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }

int main() {
  // 入力
  int N, K;
  cin >> N >> K;

  // 計算
  int count = 0;
  int n = N;
  while (n > 0) {
    int k = (n % K);
    n /= K;
    count ++;
  }
  
  // 出力
  println(count);
}
