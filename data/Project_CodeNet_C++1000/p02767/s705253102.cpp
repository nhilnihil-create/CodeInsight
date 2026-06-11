#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  REP(i,n) cin >> x[i];
  
  int ans = 10000000;

  REP(i,100){
    int y = 0;
    REP(j,n){
      y += (x[j] - i) * (x[j] - i);
    }
    ans = min(ans,y);
  }
  
  cout << ans << endl;
  
}
