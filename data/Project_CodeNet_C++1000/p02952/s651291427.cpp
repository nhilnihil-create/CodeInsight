#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int keta(int num) {
  int ans = 1;
  while (true) {
    if (num <= 9) {
      return ans;
    } else {
      num /= 10;
      ans++;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (keta(i) % 2 == 1) ++ans;
  }
  cout << ans << endl;
}
