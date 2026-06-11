#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout) {
  int n;
  cin >> n;
  int n2 = 1 << n;
  vector<int> s(n2);

  for (int i = 0; i < n2; i++) {
    cin >> s[i];
  }

  sort(s.begin(), s.end());

  vector<int> a;
  a.push_back(s.back());
  s.back() = -1;
  for (int i = 0; i < n; i++) {
    vector<int> b = a;
    sort(b.begin(), b.end());
    int idx = n2 - 1;
    while (b.size() > 0 && idx >= 0) {
      if (s[idx] == -1) {
        idx--;
        continue;
      }
      if (s[idx] < b.back()) {
        b.pop_back();
        a.push_back(s[idx]);
        s[idx] = -1;
      }
      idx--;
    }
    if (b.size() > 0) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  return;
}

#ifndef TEST
int main() {
  solve(cin, cout);
}
#endif
