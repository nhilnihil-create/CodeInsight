#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string s;
  cin >> s;
  bool ans = true;
  for(int i = 1; i < 4 ;i++){
    if(s.at(i) == s.at(i-1)) ans = false;
  }
  puts(ans ? "Good" : "Bad");
  }
