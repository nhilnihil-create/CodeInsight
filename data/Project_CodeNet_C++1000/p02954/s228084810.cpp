#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  string s;
  cin >> s;
  int len = s.size();
  vector<int> child(len, 1);
  for (int i = 0; i < len; i++) {
    if (s[i] == 'R') {
      if (s[i + 1] == 'R') {
        child[i + 2] += child[i];
        child[i] = 0;
      }
    }
    if (s[len - i - 1] == 'L') {
      if (s[len - i - 2] == 'L') {
        child[len - i - 3] += child[len - i - 1];
        child[len - i - 1] = 0;
      }
    }
  }
  for (int i = 0; i < len; i++) {
    if (i == len - 1) {
      cout << child[i] << endl;
    } else {
      cout << child[i] << " ";
    }
  }

  return 0;
}
