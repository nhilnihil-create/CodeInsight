#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;

  vector<int> p(n);
  REP(i,n) {
    cin >> p[i];
  }
  
  int ans = 0;
  int a, b;
  REP(i,n-2) {
    a = max({p[i],p[i+1],p[i+2]});
    b = min({p[i],p[i+1],p[i+2]});
    if (p[i+1] != a && p[i+1] != b) ans++;
  }
  
  cout << ans << endl;
  
}