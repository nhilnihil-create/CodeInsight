#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

int main() {
  string s;
  int i, len, flag = true;
  cin >> s;
  len = s.length();
  for (i = 0; i < len; i++)
    if (s[i] != s[len - i - 1]) flag = false;
  for (i = 0; i < (len - 1) / 2; i++)
    if (s[i] != s[(len - 1) / 2 - i - 1]) flag = false;
  for (i = (len + 3) / 2; i < len; i++)
    if (s[i] != s[len - i - 1]) flag = false;
  cout << ((flag) ? "Yes" : "No") << endl;
}
