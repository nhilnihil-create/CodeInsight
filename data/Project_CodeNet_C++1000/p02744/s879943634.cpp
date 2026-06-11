#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 'a';
  }
  queue<string> q;
  q.push("a");
  while (true) {
    string s = q.front();
    q.pop();
    if ((int)s.length() == n) break;
    char mxS = *max_element(s.begin(), s.end());
    for (char c = 'a'; c <= mxS + 1; c++) {
      string ss = s;
      ss += c;
      if ((int)ss.length() == n) {
        cout << ss << '\n';
      }
      q.push(ss);
    }
  }
  return 0;
}