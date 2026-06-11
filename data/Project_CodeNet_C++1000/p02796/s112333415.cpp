#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> P(N);
  for (int i = 0; i < N; i++) {
    int X, L;
    cin >> X >> L;
    P.at(i).first = X + L;
    P.at(i).second = X - L;
  }
  sort(P.begin(), P.end());
  int ans = 0, T = -1100000000;
  for (int i = 0; i < N; i++) {
    if (T <= P.at(i).second) {
      ans++;
      T = P.at(i).first;
    }
  }
  cout << ans << endl;
}