#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int main() {
  string s;
  cin >> s;
  bool ans = true;
  rep(i,s.size()){
    if(i%2 == 0 && s.at(i) == 'L' || i%2 != 0 && s.at(i) == 'R') ans = false;
  }
  puts(ans ? "Yes":"No");
  }
