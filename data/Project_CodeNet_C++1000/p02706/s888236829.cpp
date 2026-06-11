#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for(int i = 0;i < m;i++){
    cin >> a.at(i);
  }
  int s = 0;
  for(int i = 0;i < m;i++){
    s += a.at(i);
  }
  int ans = n - s;
  if(ans >= 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
    
}
