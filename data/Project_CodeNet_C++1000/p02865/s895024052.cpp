#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  int ans = 0;
  for( int i = 1; i <= (N+1)/2; i++ ){
    if( i != (N+1)/2 ){
      ans++;
    }
  }
  
  cout << ans << endl;
            
}
