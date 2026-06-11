#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int N, M;
  string S;
  cin >> N >> M >> S;

  vector<int> hist;
  int pos = N;
  while (pos > M) {
    bool a = false;
    for (int i = M; i > 0; i--) {
      if (S[pos-i] == '0') {
        hist.push_back(i);
        a = true;
        pos = pos-i;
        break;
      }
    }

    if (a == false) {
      cout << -1 << endl;
      return;
    }
  }

  hist.push_back(pos);

  reverse(hist.begin(), hist.end());
  for (int x:hist) {
    cout << x << " ";
  }
  cout << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
