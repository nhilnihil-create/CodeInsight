#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  int q;
  cin >> s >> q;
  int r, f;
  char c;
  int head = 1;
  string headstr = "";
  string tailstr = "";
  for (int i = 0; i < q; ++i) {
    cin >> r;

    if (r == 1) {
      head = head == 1 ? 2 : 1;

    } else {
      cin >> f >> c;

      if (f == head) {
        headstr += c;
      } else {
        tailstr += c;
      }
    }
  }

  string result;
  if (head == 1) {
    reverse(headstr.begin(), headstr.end());
    result = headstr + s + tailstr;
  } else {
    reverse(tailstr.begin(), tailstr.end());
    reverse(s.begin(), s.end());
    result = tailstr + s + headstr;
  }

  cout << result << endl;
  return 0;
}