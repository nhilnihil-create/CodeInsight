#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;

  string rev1 = s;
  reverse(rev1.begin(), rev1.end());

  string s2 = s.substr(0, (s.length() - 1) / 2);
  string rev2 = s2;
  reverse(rev2.begin(), rev2.end());

  string s3, rev3;
  s3 = rev3 = s.substr((s.length() + 3) / 2 - 1, s.length());
  reverse(rev3.begin(), rev3.end());

  if (rev1 == s && rev2 == s2 && rev3 == s3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
