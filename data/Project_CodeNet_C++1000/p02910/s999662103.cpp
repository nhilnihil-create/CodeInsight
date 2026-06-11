#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  bool f = true;
  rep(i, S.size()) {
    if ((i + 1) % 2 == 1 && (S[i] != 'R' && S[i] != 'U' && S[i] != 'D')) {
      cout << "No" << endl;
      return 0;
    }
    if ((i + 1) % 2 == 0 && (S[i] != 'L' && S[i] != 'U' && S[i] != 'D')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}