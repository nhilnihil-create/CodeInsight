#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> d(n + 1);
  rep(i, n+1) {
    if(i == 0) d[i] = 0;
    else if(i > 0) {
      int l;
      cin >> l;
      d[i] = d[i-1] + l;
    }
  }
  int ans = 0;
  for(int i = 1; i < n+1; i++) {
    if(d[i-1] <= x && x < d[i]) ans = i;
    else if(x >= d[i]) ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}
  
    
      