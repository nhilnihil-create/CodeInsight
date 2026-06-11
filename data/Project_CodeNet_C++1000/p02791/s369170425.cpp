#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  
  int ans = 0;
  int mn = p[0];
  REP(i,n){
      if(p[i] == min(mn,p[i])){
        ans++;
        mn = min(mn,p[i]);
      }
    
  }
  
  cout << ans << endl;
  
}
