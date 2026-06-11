#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> A.at(i).at(j);
  int N;
  cin >> N;
  vector<int> b(N);
  rep(i, N) cin >> b.at(i);
  rep(i, 3) rep(j, 3) rep(k, N) if (A.at(i).at(j) == b.at(k)) A.at(i).at(j) = 0;
  bool ans = false;
  rep(i, 3) if (A.at(i).at(0) == 0 && A.at(i).at(1) == 0 && A.at(i).at(2) == 0) ans = true;
  rep(i, 3) if (A.at(0).at(i) == 0 && A.at(1).at(i) == 0 && A.at(2).at(i) == 0) ans = true;
  if (A.at(0).at(0) == 0 && A.at(1).at(1) == 0 && A.at(2).at(2) == 0) ans = true;
  if (A.at(0).at(2) == 0 && A.at(1).at(1) == 0 && A.at(2).at(0) == 0) ans = true;
  if (ans == true) cout << "Yes";
  else cout << "No";
}
