#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int a1, a2, a3;
  string ans;
  
  cin >> a1 >> a2 >> a3;
  
  if(a1 + a2 + a3 >= 22) ans = "bust";
  else ans = "win";
  
  cout << ans << endl;
  return 0;
}