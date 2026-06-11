#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int a, b;
  int ans;
  
  cin >> a >> b;
  
  ans = a+b;
  if(ans%2 != 0) cout << "IMPOSSIBLE" << endl;
  else{
    ans /= 2;
    cout << ans << endl;
  }
  return 0;
}