#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int h,a;
  cin >> h >> a;
  
  int ans = 0;
  
  while(1){
    h -= a;
    ans++;
    if(h <= 0) break;
  }
  
  cout << ans << endl;
  
}
