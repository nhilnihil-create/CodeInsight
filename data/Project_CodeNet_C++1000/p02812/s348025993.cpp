#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t N;
  string S;
  cin >> N;
  cin >> S;
  int ans{};
  size_t start{};
  while (start < N) {
    size_t cur = S.find("ABC", start);
    if (cur != string::npos) {
      ++ans;
      start = cur + 3;
    } else {
      start = N;
    }
  }

  cout << ans << endl;
  return 0;
}
