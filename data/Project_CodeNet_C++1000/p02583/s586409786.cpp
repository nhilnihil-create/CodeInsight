#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  vector<int> ls;
  cin >> n;
  ls.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ls[i];
  }
  sort(ls.begin(), ls.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (ls[i] != ls[j] && ls[j] != ls[k] && ls[k] != ls[i] &&
            ls[i] + ls[j] > ls[k]) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}
