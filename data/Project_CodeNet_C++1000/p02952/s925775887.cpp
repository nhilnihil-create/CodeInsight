#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans{};
  for (int i{1}; i <= N; ++i) {
    int num = static_cast<int>(log10(i) + 1);
    if (num % 2 == 1)
      ++ans;
  }

  cout << ans << endl;
  return 0;
}
