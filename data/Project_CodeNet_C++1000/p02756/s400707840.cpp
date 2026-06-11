#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  int q;
  cin >> s >> q;
  int t, f;
  char c;
  bool isrev = false;
  deque<char> deq;
  rep(i, s.size()) { deq.push_back(s[i]); }
  rep(i, q) {
    cin >> t;
    if (t == 1) {
      isrev = !isrev;
    } else {
      cin >> f >> c;
      if (isrev) {
        if (f == 1) {
          deq.push_back(c);
        } else {
          deq.push_front(c);
        }
      } else {
        if (f == 1) {
          deq.push_front(c);
        } else {
          deq.push_back(c);
        }
      }
    }
  }
  if (isrev) {
    while (!deq.empty()) {
      cout << deq.back();
      deq.pop_back();
    }
  } else {
    while (!deq.empty()) {
      cout << deq.front();
      deq.pop_front();
    }
  }
  cout << endl;
  return 0;
}