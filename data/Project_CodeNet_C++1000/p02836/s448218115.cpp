#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  string S; cin >> S;

  int ans = 0;
  for (int i = 0; i < S.size() / 2; i++) {
    if (S[i] != S[S.size() - 1 - i]) ans++;
  }
  cout << ans << endl;
}