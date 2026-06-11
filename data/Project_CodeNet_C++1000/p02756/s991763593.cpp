#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)
int main() {
  struct query {
    int t;
    int f;
    char c;
  };

  string s;
  cin >> s;
  int Q;
  cin >> Q;
  vector<query> queries(Q);
  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      queries[i].t = t;
    } else if (t == 2) {
      int f;
      char c;
      cin >> f >> c;

      queries[i].t = t;
      queries[i].f = f;
      queries[i].c = c;
    }
  }
  string prepend = "";
  string append = "";

  bool rev = false;
  for (const auto& q : queries) {
    if (q.t == 1) {
      rev = !rev;
      swap(prepend, append);
    } else if (q.t == 2) {
      if (q.f == 1) {
        prepend.push_back(q.c);
      } else if (q.f == 2) {
        append.push_back(q.c);
      }
    }
  }

  string ret;
  reverse(prepend.begin(), prepend.end());
  if (rev) {
    reverse(s.begin(), s.end());
  }
  ret = prepend + s + append;
  cout << ret << endl;
  return 0;
}
