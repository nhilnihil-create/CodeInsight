#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  deque<char> dq;

  if (n == 1) {
    if (s == "?")
      cout << "D" << endl;
    else
      cout << s << endl;
    return 0;
  } else if (n == 2) {
    if (s == "??")
      cout << "PD";
    else if (s == "?P")
      cout << "DP";
    else if (s == "P?")
      cout << "PD";
    else if (s == "?D")
      cout << "PD";
    else if (s == "D?")
      cout << "DD";
    cout << endl;
    return 0;
  }

  rep(i, n - 1) {
    if (s[i] == 'D' || s[i] == 'P')
      dq.push_back(s[i]);
    else if (s[i] == '?') {
      if (0 < i) {
        if (dq.back() == 'P')
          dq.push_back('D');
        else if (dq.back() == 'D')
          if (s[i + 1] == 'D' || s[i + 1] == '?')
            dq.push_back('P');
          else
            dq.push_back('D');
      } else if (i == 0) {
        if (s[1] == 'D' || s[1] == '?')
          dq.push_back('P');
        else
          dq.push_back('D');
      } else if (i == n - 1) {
        dq.push_back('D');
      }
    }
  }

  if (s[n - 1] == '?')
    dq.push_back('D');
  else
    dq.push_back(s[n - 1]);

  while (dq.size()) cout << dq.front(), dq.pop_front();

  cout << endl;
  return 0;
}
