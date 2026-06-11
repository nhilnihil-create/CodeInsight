#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;

  vector<vector<int>> dp(26 + 'a', vector<int>());
  for (int i = 0; i < S.length(); i++) {
    dp[S[i]].push_back(i);
  }

  for (int j = 0; j < T.length(); j++) {
    if (dp[T[j]].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  int output = 0;
  int i = -1;
  for (int j = 0; j < T.length(); j++) {
    bool found = false;
    for (int k = 0; k < dp[T[j]].size(); k++) {
      if (dp[T[j]][k] > i) {
        i = dp[T[j]][k];
        found = true;
        break;
      }
    }
    if (!found) {
      output++;
      i = -1;
      j--;
    }
  }

  cout << output * S.length() + i + 1 << endl;

  return 0;
}
