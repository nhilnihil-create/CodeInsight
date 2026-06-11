#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n),b(m);
  for ( int i=0; i<n; i++ ) cin >> a[i];
  for ( int i=0; i<m; i++ ) cin >> b[i];
  int mia=1e9,mib=1e9;
  for ( int i=0; i<n; i++ ) mia=min(mia,a[i]);
  for ( int i=0; i<m; i++ ) mib=min(mib,b[i]);
  int ans=mia+mib;  
  for ( int i=0; i<k; i++ ) {
    int x,y,z;
    cin >> x >> y >> z;
    --x; --y;
    ans=min(ans,a[x]+b[y]-z);
  }
  cout << ans << '\n';
  return 0;
}
