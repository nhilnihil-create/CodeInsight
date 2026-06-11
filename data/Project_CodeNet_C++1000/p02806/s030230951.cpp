#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<string, int>> vp(n);
  for (int i = 0; i < n; i++) {
    cin >> vp[i].first >> vp[i].second;
  }
  string x;
  cin >> x;

  bool sleep = false;
  int time = 0;
  for (int i = 0; i < n; i++) {
    if (sleep) {
      time += vp[i].second;
    }
    if (vp[i].first == x) sleep = true;
  }

  cout << time << endl;
}