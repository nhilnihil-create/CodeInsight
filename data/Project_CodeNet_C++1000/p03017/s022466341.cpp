#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool can_reach(string s, int start, int end) {
  for (int i = start; i + 1 <= end; i++)
    if (s.substr(i, 2) == "##") return false;
  return true;
}

bool can_overlap(string s, int start, int end) {
  for (int i = start; i <= end; i++) {
    if (s.substr(i - 1, 3) == "...") return true;
  }
  return false;
}

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--, b--, c--, d--;

  if (!can_reach(s, a, c) || !can_reach(s, b, d)) {
    cout << "No" << endl;
    return 0;
  }

  if (c > d && !can_overlap(s, b, d)) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}
