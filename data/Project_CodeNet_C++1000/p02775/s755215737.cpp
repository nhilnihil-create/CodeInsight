#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  S += '0';
  int ans = 0;
  for (int i = 0; i + 1 < S.size(); i++) {
    int tmp = S.at(i) - '0';
    ans += min(tmp, 10 - tmp);
    if (tmp >= 6 || tmp == 5 && S.at(i + 1) >= '5') S.at(i + 1)++;
  }
  ans += S.back() - '0';
  cout << ans << "\n";
}