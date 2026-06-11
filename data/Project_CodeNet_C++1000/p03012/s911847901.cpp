#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int w[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
  }

  int ans = (1U << 31) - 1;
  int left = 0;
  for (int i = 0; i < n - 1; i++) {
    left += w[i];
    ans = min(ans, abs(sum - left - left));
  }

  cout << ans << endl;
}