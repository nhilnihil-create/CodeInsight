#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int a, b, c;
  int ans;
  
  cin >> a >> b >> c;
  
  if(a == b && a != c) cout << "Yes" << endl;
  else if(a == c && a != b) cout << "Yes" << endl;
  else if(c == b && a != c) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}