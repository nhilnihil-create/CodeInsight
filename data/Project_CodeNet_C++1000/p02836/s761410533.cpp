#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  int ans = 0;
  rep(i, s.size()){
    if (s[i] != t[i]) ans++;
  }
  cout << ans / 2 << endl;
}
