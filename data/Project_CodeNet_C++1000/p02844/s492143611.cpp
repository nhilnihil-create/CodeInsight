#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  int ans{};
  for (int i{}; i <= 999; ++i) {
    stringstream ss;
    ss << setw(3) << setfill('0') << i;
    string digits{ss.str()};
    int cur{};
    for (int j{}; j < N; ++j) {
      if (S[j] == digits[cur]) {
        if (++cur == 3) {
          ++ans;
          break;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
