#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int cnt = 0;
    int num = i;
    while (num > 0) {
      cnt++;
      num /= 10;
    }
    if (cnt % 2 == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}