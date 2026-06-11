#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  vector<int> abc(3);
  for (int i = 0; i < 3; ++i) cin >> abc[i];
  int k;
  cin >> k;

  int ans = 0;
  for (int i = 0; i < 2; ++i) {
    while (true) {
      if (abc[i] >= abc[i + 1]) {
        ++ans;
        abc[i + 1] *= 2;
      } else {
        break;
      }
    }
  }

  if (ans <= k) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
