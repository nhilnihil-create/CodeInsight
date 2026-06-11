#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<string> u(n);
  for(int i=0;i<n;++i) cin >> u[i];
  int m,now=0; cin >> m;
  string t;
  for(int i=0;i<m;++i){
    cin >> t;
    int j;
    for(j=0;j<n;++j){
      if(u[j]==t) break;
    }
    if(j!=n){
      if(now) cout << "Closed by " << t;
      else cout << "Opened by " << t;
      now=1-now;
    } else cout << "Unknown " << t;
    cout << endl;
  }
  
  return 0;
}
