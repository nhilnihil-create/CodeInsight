#include <bits/stdc++.h>
#include <regex>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  int n;
  int ans;
  
  cin >> n;
  
  if(n % 1000 == 0) cout << 0 << endl;
  else{
    ans =1000 - n % 1000;
    cout << ans << endl;
  }
  
  return 0;
}