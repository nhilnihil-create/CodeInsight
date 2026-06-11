#include <bits/stdc++.h>
#include <regex>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int n, x, t;
  int ans;
  
  cin >> n >> x >> t;
  
  ans = n / x;
  if(n%x != 0) ans++;
  ans *= t;
  
  cout << ans << endl;
  
  return 0;
}