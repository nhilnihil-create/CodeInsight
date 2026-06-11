#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  deque<char> D;
  for (char c : S) D.push_back(c);
  bool b = 0;
  int Q;
  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      b ^= 1;
    }
    if (q == 2) {
      int n;
      char c;
      cin >> n >> c;
      if (n == 1) {
        if (!b) D.push_front(c);
        else D.push_back(c);
      }
      if (n == 2) {
        if (!b) D.push_back(c);
        else D.push_front(c);
      }
    }
  }
  if (b) reverse(D.begin(), D.end());
  for (auto d : D) cout << d;
  cout << "\n";
}