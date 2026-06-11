#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  set<int> s;
  s.insert(x);
  s.insert(y);
  s.insert(z);
  if ((int)s.size() == 2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}