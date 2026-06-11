#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A, B, K;
  cin >> K;
  cin >> A >> B;
  for (int i = A; i <= B; ++i) {
    if (i % K == 0) {
      puts("OK");
      return 0;
    }
  }
  puts("NG");

  return 0;
}
