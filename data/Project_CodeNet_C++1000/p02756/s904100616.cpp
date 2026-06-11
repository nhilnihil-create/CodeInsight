#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  string front, behind;
  bool isfront = 0;
  rep(i, q) {
    int t, f;
    char c;
    cin >> t;
    if (t == 1) {
      isfront ^= 1;
    } else {
      cin >> f >> c;
      if (f == 1) {
        if (isfront)
          behind.push_back(c);
        else
          front.push_back(c);
      } else {
        if (isfront)
          front.push_back(c);
        else
          behind.push_back(c);
      }
    }
  }
  if (isfront) {
    reverse(s.begin(), s.end());
    reverse(behind.begin(), behind.end());
    cout << behind + s + front << endl;
  } else {
    reverse(front.begin(), front.end());
    cout << front + s + behind << endl;
  }
  return 0;
}