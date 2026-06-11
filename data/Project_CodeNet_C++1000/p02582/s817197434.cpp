#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  string S;
  cin >> S;
  int res = 0;
  int a = 0;
  rep(i,S.size()){
    if (S[i] == 'R')
      a++;
    else{
      res = max(res,a);
      a = 0;
    }
  }
  cout << max(res,a) << endl;
}