#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int l;
  cin >> l;
  
  
  double ans = l*l*l;
  ans /= 27;
  
  
  cout << fixed << setprecision(12) << ans << endl;
    
}