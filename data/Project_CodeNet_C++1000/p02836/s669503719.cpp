#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  int n = s.size();
  int ans = 0;
  REP(i,n/2){
    if(s[i] != s[n-i-1]) ans++;
  }
  cout << ans << endl;
}