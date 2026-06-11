#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int n, ans;
  
  cin >> n;
  
  ans = n/2;
  if(n%2 > 0) ans++;
  cout << ans << endl;
  
  return 0;
}