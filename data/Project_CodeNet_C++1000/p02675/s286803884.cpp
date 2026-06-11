#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  string s;
  cin >> s;
  char last = s[s.length() - 1];
  if (last == '3') {
    cout << "bon" << endl;
  } else if (last == '0' || last == '1' || last == '6' || last == '8') {
    cout << "pon" << endl;
  } else {
    cout << "hon" << endl;
  }
  return 0;
}
