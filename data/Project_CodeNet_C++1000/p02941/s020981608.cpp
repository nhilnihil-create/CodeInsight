#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long a[n], b[n];
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) cin>>b[i];
  long long ans = 0;
  while (true) {
    bool ok = true;
    for (int i=0; i<n; i++) {
      if (a[i] == b[i]) {
        continue;
      }
      if (b[i] < a[i]) {
        cout<<-1<<endl;
        return 0;
      }
      int ip = ((i - 1) + n) % n;
      int in = (i + 1) % n;
      if (b[i] == b[ip] || b[i] == b[in]) {
        cout<<-1<<endl;
        return 0;
      }
      ok = false;
      if (b[i] < b[ip] || b[i] < b[in]) {
        continue;
      }
      long dest = max(a[i], max(b[ip], b[in]));
      long tmp = (b[i] - dest - 1) / (b[ip] + b[in]) + 1;
      ans += tmp;
      b[i] -= (b[ip] + b[in]) * tmp;
    }
    // cout<<ans<<endl;
    // for (int i=0; i<n; i++) {
    //   cout<<b[i]<<" ";
    // }
    // cout<<endl;
    if (ok) {
      cout<<ans<<endl;
      return 0;
    }
  }
}