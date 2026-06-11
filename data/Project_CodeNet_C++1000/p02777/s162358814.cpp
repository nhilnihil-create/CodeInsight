#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  string s, t, u;
  int a, b;
  int ans_a, ans_b;
  
  cin >> s >> t >> a >> b >> u;
  
  if(u == s){
    ans_a = a - 1;
    ans_b = b;
  }
  else{
    ans_a = a;
    ans_b = b - 1;
  }
  
  cout << ans_a << " " << ans_b << endl;
  return 0;
}