#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  int ans = 0;
  
  int an[n];
  REP(i,n) an[i] = -1;
  
  REP(i,m){
    int s,c;
    cin >> s >> c;
    s--;
    
    if(n != 1 && s == 0 && c == 0){
      cout << -1 << endl;
      return 0;
    }
    
    if(an[s] < 0 || an[s] == c){
      an[s] = c;
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }
  
  if(n != 1){
    REP(i,n){
      if(i != 0 && an[i] == -1){
        an[i] = 0;
      }
      else if(an[i] == -1){
        an[i] = 1;
      }
    }
  }
  else{
    if(an[0] == -1){
      an[0] = 0;
    }
  }
  
  REP(i,n){
    ans += an[i];
    if(i != n-1){
      ans *= 10;
    }
  }
  
  
  
  cout << ans << endl;
}