#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
  }
  
  vector<int> b(n);
  REP(i,n) {
    cin >> b[i];
  }
  
  vector<int> c(n-1);
  REP(i,n-1) {
    cin >> c[i];
  }
    
  int ans = 0;
  
  REP(i,n) { 
    ans += b[a[i]-1];
    if (i > 0 && a[i]-1 == a[i-1]) ans += c[a[i]-2];
  }
  
  cout << ans << endl;
     
}