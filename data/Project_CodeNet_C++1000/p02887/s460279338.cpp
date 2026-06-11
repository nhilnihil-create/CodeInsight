#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int ans = 1;
  REP(i,n){
    if(i != n-1){
      if(s[i] != s[i+1]){
        ans++;
      }
    }
  }
  
  cout << ans << endl;
  
}