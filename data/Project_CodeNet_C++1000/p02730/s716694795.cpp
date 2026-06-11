#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  string s;
  cin >> s;

  string t = s;
  reverse(t.begin(), t.end());
  if(s == t) {
    int x = (s.size() - 1) / 2;
    rep(i, x) {
      if(s[i] != t[x - i - 1]) {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
    return 0;
  }
  cout << "No";
}
