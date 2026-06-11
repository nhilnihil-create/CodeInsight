#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string S, T;
  int ans = 0;

  cin >> S >> T;

  for (size_t i = 0; i < S.length(); i++) {
    if (S[i] != T[i]) { 
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}