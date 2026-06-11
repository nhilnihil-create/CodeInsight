#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans{};
  for (int i{1}; N >= i; i *= 100) {
    ans += min(i*10-1, N) - (i - 1);
  }

  cout << ans << endl;
  return 0;
}
