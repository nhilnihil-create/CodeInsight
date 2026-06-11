#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  priority_queue<int> A, B, C, D;

  rep(i, a) {
    int p;
    cin >> p;
    A.push(p);
  }

  rep(i, b) {
    int q;
    cin >> q;
    B.push(q);
  }

  rep(i, c) {
    int r;
    cin >> r;
    C.push(r);
  }

  rep(i, x) {
    D.push(A.top());
    A.pop();
  }

  rep(i, y) {
    D.push(B.top());
    B.pop();
  }

  ll sum = 0;
  rep(i, x + y) {
    if (C.top() > D.top() && !C.empty()) {
      sum += C.top();
      C.pop();
    } else {
      sum += D.top();
      D.pop();
    }
  }

  cout << sum << endl;

  return 0;
}
