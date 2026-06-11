#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> AB(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> AB.at(i).at(1) >> AB.at(i).at(0);
  }
  sort(AB.begin(), AB.end());
  int64_t A = 0;
  bool ok = true;
  for (int i = 0; i < N; i++) {
    A += AB.at(i).at(1);
    if (A > AB.at(i).at(0)) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
      