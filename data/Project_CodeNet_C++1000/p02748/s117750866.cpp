#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> x(a), y(b);
  vector<int> u(m), v(m), c(m);
  for(auto&& t:x)cin >> t;
  for(auto&& t:y)cin >> t;
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> c[i];
    u[i]--;v[i]--;
  }
  int ans = 100000000;
  for(int i=0;i<m;i++){
    ans = min(x[u[i]] + y[v[i]] - c[i], ans);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  cout << min(ans, x[0] + y[0]) << endl;
}
