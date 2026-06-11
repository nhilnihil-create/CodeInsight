#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> v(n, false);
  for(int i=0;i<k;i++) {
    int d;
    cin >> d;
    for(int j=0;j<d;j++) {
      int a;
      cin >> a;
      a--;
      if(!v[a]) v[a] = !v[a];
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(!v[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
