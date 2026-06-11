#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  char a;
  string ans;
  
  cin >> a;
  
  if(isupper(a)) ans = "A";
  else ans = "a";
  
  cout << ans << endl;
  return 0;
}