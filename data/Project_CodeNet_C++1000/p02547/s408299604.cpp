#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, cnt = 0;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> v[i][0] >> v[i][1];
  }

  for (int i = 0; i < N; i++) {
    if (v[i][0] == v[i][1]) {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}