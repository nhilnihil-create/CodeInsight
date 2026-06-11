#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> d(n);
  REP(i,n) {
    cin >> d[i];
  }
  
  int ans = 0;
  REP(i,n) {
    REP(j,n) {
      if(i != j) ans += d[i]*d[j];
    }
  }
  
  cout << ans/2 << endl;
    
}