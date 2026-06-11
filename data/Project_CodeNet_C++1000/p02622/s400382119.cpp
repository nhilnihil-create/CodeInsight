#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, ans = 0;
  string S, T;
  cin >> S >> T;
  n = S.size();

  for (int i = 0; i < n; i++) {
    if (S[i] != T[i]) ans++;
  }
  
  cout << ans << endl;
}