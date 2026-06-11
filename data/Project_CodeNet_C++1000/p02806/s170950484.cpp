#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> S.at(i) >> T.at(i);
  string X;
  cin >> X;
  bool F = false;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (F) ans += T.at(i);
    if (X == S.at(i)) F = true;
  }
  cout << ans << endl;
}