#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  string s; cin >> s;
  if (s.length() % 2) {
    cout << "No" << endl;
    return 0;
  }
  int tmp = 0;
  while (tmp + 1 < s.length()) {
    if (s[tmp] == 'h' && s[tmp+1] == 'i') {
      tmp += 2;
    }
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
