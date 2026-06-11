#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int k, x;
  string ans;
  
  cin >> k >> x;
  
  if(500 * k >= x) ans = "Yes";
  else ans = "No";
    
  cout << ans << endl;
  return 0;
}