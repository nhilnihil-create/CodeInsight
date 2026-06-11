#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  string S;
  string T;
  cin >> S >> T;
  int res = 0;
  rep(i,3){
    if (S[i]==T[i])
      res++;
  }
  cout << res << endl;
}