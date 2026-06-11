#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  rep(i, N - 2) {
    if (S.substr(i, 3) == "ABC") ans++;
  }
  cout << ans << endl;
  return 0;
}