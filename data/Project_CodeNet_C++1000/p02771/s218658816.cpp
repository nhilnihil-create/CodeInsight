#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  set<int> s;
  for (int i = 0; i < 3; ++i) {
    int a;
    cin >> a;
    s.insert(a);
  }
  if (s.size() == 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
