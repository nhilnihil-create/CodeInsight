#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  bool ok = true;
  int n = s.size();
  REP(i,n){
    if(s[i] != s[n-i-1]) ok = false;
  }
  
  int m = n/2;
  REP(i,m){
    if(s[i] != s[m-i-1]) ok = false;
  }
  
  
  if(ok) cout << "Yes" << endl;
  else  cout << "No" << endl;
  
}