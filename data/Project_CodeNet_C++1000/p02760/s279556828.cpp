#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> A(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }
  int N;
  cin >> N;
  unordered_set<int> b;
  int tmp;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    b.insert(tmp);
  }

  vector<vector<bool>> v(3, vector<bool>(3));
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      auto it = b.find(A.at(r).at(c));
      if (it == b.end()) {
        v.at(r).at(c) = false;
      } else {
        v.at(r).at(c) = true;
      }
    }
  }

  for (int r = 0; r < 3; ++r) {
    if (v[r][0] && v[r][1] && v[r][2]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for (int c = 0; c < 3; ++c) {
    if (v[0][c] && v[1][c] && v[2][c]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (v[0][0] && v[1][1] && v[2][2]) {
    cout << "Yes" << endl;
    return 0;
  }
  if (v[0][2] && v[1][1] && v[2][0]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
