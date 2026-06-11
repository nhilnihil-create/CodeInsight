#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  
  vector<int> a(n,0);
  REP(i,n){
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  int ans = 0;
  
  REP(i,k){
    ans += a[i];
  }
  
  cout << ans << endl;
    
  

}