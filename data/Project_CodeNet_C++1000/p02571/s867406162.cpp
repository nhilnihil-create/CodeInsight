#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int res = 1001, sl = s.size(), tl = t.size();
  for (int offset = 0; offset <= sl - tl; ++offset) {
    int cnt = 0;
    for (int i = 0; i < tl; ++i) if (s[offset + i] != t[i]) cnt++;
    res = min(cnt, res);
  }

  cout << res << endl;
}
