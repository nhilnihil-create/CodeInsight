#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;

  string ans = "";
  rep(i, 0, N) {
    ans.push_back(S[i]);
    ans.push_back(T[i]);
  }

  cout << ans << endl;

  return 0;
}
