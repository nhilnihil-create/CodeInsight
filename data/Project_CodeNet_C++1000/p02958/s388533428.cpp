#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) q[i] = i+1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != q[i]) cnt++;
    if (cnt == 3) break;
  }
  if(cnt == 3) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}