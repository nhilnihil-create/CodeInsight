#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  
  REP(i,n){
    if((i+1) % 3 == 0 || (i+1) % 5 == 0 ){
      continue;
    }
    ans += i+1;
  }
  
  cout << ans << endl;
    

 
  
}