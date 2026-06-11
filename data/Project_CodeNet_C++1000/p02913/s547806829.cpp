#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j + i < N; j++) {
      if (S.at(j) == S.at(j + i)) cnt++;
      else cnt = 0;
      ans = max(ans, min(i, cnt));
    }
  }
  cout << ans << "\n";
}