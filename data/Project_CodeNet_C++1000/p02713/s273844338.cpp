#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
  int k;
  cin >> k;
  
  ll ans = 0;
  REP(i,k){
    REP(j,k){
      REP(l,k){
        ans += GCD(GCD((i+1), (j+1)),GCD((j+1), (l+1)));
      }
    }
  }
  
  cout << ans << endl;
  
}
