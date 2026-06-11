#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;

  int dir = 1;
  vector<char> front;
  vector<char> back;

  rep(i, q) {
    int t;
    cin >> t;

    if (t == 1) {
      dir *= -1;
    } else {
      int f;
      cin >> f;
      char c;
      cin >> c;

      if (f == 1) {
        if (dir == 1) {
          front.push_back(c);
        } else {
          back.push_back(c);
        }
      } else {
        if (dir == 1) {
          back.push_back(c);
        } else {
          front.push_back(c);
        }
      }
    }
  }

  if (dir == 1) {
    reverse(front.begin(), front.end());
    for (char fc : front) {
      cout << fc;
    }
    cout << s;
    for (char bc : back) {
      cout << bc;
    }

  } else {
    reverse(back.begin(), back.end());
    for (char bc : back) {
      cout << bc;
    }
    reverse(s.begin(), s.end());
    cout << s;
    for (char fc : front) {
      cout << fc;
    }
  }

  return 0;
}
