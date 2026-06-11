#include<bits/stdc++.h>
using namespace std;

signed main() {
  int N,L; cin >> N >> L;
  int sum = 0;
  for(int i = 0; i<N; i++) sum += i+L;
  int ans = 2e9;
  int mn = 2e9;
  for(int i = 0; i<N; i++) {
    if(mn > abs(i+L)) {
      mn= min(abs(i+L), mn);
      ans = sum - (i+L);
    }
  }
  cout << ans << endl;
}
