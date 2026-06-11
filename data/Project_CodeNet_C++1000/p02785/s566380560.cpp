#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  
  REP(i,n) cin >> h[i];
  
  sort(h.begin(), h.end());
  
  ll ans = 0;
  
  REP(i,n-k){
    ans += h[i];
  }
  
  
  cout << ans << endl;
  
}
