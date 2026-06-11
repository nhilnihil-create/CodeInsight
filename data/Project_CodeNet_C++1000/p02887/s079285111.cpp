#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 1;
  char now;
  //cout << cnt;
  rep(i,s.size()){
      if (i == 0)now = s[i];
      else{
          if (s[i] != now)cnt += 1;
          now = s[i];
      }
  }
  cout << cnt;
}