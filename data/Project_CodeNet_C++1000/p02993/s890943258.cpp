#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  if (s[0] != s[1] && s[1] != s[2] && s[2] != s[3]) {
    cout << "Good" << endl;
  } else {
    cout << "Bad" << endl;
  }
  return 0;
}
