#include<bits/stdc++.h>
using namespace std;

signed main() {
  int N; cin >> N;
  vector<int> W(N);
  for(int i=0; i<N; i++) cin >> W[i];

  int sum = 0;
  for(int i=0; i<N; i++) sum += W[i];

  int ans = 1e9;
  for(int t=0; t<N; t++) {
    int s1=0;
    for(int i=0; i<t; i++) s1 += W[i];
    int s2 = sum - s1;
    ans = min(ans, abs(s1-s2));    
  }
  cout << ans << endl;
}
