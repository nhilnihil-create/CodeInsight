#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int b1;
  cin >> b1;
  int ans = 0;
  ans += b1;
  REP(i,n-1){
    int b2;
    cin >> b2;
    
    ans += min(b1,b2);
    
    b1 = b2;
  }

  
  cout << ans << endl;
  
}