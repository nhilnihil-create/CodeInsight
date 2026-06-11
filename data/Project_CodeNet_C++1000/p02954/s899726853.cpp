#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)
#define FOR(i, b, n) for (long i = b; i < n; ++i)

using namespace std;

void solve(string S) {

  vector<long> ans(S.length(), 0);

  long l(0), m(0), r(S.length());

  REP(i, S.length() - 1) {
    if (S.substr(i, 2) == "RL")
      m = i;

    if (S.substr(i, 2) == "LR") {
      r = i;
      ans[m] = (m - l) / 2 + 1 + (r - m) / 2;
      ans[m + 1] = (m - l + 1) / 2 + (r - m + 1) / 2;
      l = i + 1;
    }
  }
  r = S.length() - 1;
  ans[m] = (m - l) / 2 + 1 + (r - m) / 2;
  ans[m + 1] = (m - l + 1) / 2 + (r - m + 1) / 2;
  
  REP(i, S.length())
    cout << (i ? " " : "") << ans[i];
  cout << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  solve(S);

  return 0;
}
