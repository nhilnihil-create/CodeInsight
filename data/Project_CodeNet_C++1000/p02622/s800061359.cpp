#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S,T;
  cin >> S >> T;
  int cnt = 0;

  for (int i = 0; i < S.size(); ++i) {
    if (S[i] != T[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
