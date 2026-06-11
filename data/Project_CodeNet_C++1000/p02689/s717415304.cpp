#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) v[i] = i+1;
  vector<int> h(n);
  for(int i=0; i<n; i++) cin >> h[i];
  
  int a, b;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    if(h[a-1]==h[b-1]) v[a-1]=0, v[b-1]=0;
    else if(h[a-1]>h[b-1]) v[b-1]=0;
    else v[a-1]=0;
  }
  
  int ans = 0;
  for(int i=0; i<n; i++) if(v[i]!=0) ans++;
  
  cout << ans << endl;
  return 0;
}