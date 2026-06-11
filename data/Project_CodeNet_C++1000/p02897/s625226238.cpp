#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int n, c, k = 0;
  double ans;
  
  cin >> n;
  
  c = n;
  while(c != 0){
    if(c%2 != 0) k++;
    c--;
  }
  
  ans = (double)k / (double)n;
  cout << ans << endl;
  return 0;
}