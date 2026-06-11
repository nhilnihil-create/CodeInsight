#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const vector<char> C = {'M', 'A', 'R', 'C', 'H'};

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<int> t(q), f(q);
  vector<char> c(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i];
    if (t[i] == 2) cin >> f[i] >> c[i];
  }

  deque<char> ans;
  for (int i = 0; i < s.length(); i++) ans.push_back(s[i]);

  bool forward = false;
  for (int i = 0; i < q; i++) {
    if (t[i] == 1) {
      forward = !forward;
      continue;
    }
    if (f[i] == 1 && !forward || f[i] == 2 && forward) {
      ans.push_front(c[i]);
    } else {
      ans.push_back(c[i]);
    }
  }

  if (forward) reverse(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
  printf("\n");
}
