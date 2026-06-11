#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  string s, t;
  int ans = 0;
  
  cin >> s >> t;
  
  if(s[0] == t[0]) ans++;
  if(s[1] == t[1]) ans++;
  if(s[2] == t[2]) ans++;
  
  cout << ans << endl;
  
  return 0;
}