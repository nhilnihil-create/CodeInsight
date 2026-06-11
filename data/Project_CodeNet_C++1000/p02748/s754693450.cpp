#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  int a2[a], b2[b];
  for(int i=0; i<a; i++) cin >> a2[i];
  for(int i=0; i<b; i++) cin >> b2[i];
  int x[m], y[m], c[m];
  for(int i=0; i<m; i++) {
    cin >> x[i] >> y[i] >> c[i];
  }
  long ans1=1e12;
  for(int i=0; i<m; i++) {
    if(ans1>a2[x[i]-1]+b2[y[i]-1]-c[i]) ans1=a2[x[i]-1]+b2[y[i]-1]-c[i];
  }
  sort(a2, a2+a);
  sort(b2, b2+b);
  if(ans1>a2[0]+b2[0]) ans1=a2[0]+b2[0];
  cout << ans1 << endl;
}