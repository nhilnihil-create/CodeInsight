#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  
  REP(i,n) cin >> v[i];
  
  sort(v.begin(),v.end());
  
  double ans;
  
  ans += v[0];
  
  REP(i,n-1){
    ans += v[i+1];
    ans /= 2;
  }
  
  cout << ans << endl;
  
  

  
}