#include <bits/stdc++.h>
using namespace std;
int main() {
  int m,d;
  cin >> m >> d;
  int ans=0;
  for ( int i=1; i<=m; i++ ) {
    for ( int j=2; j<10; j++ ) {
      for ( int k=2; k<10; k++ ) {
        if ( j*10+k<=d && j*k==i ) ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}