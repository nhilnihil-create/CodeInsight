#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  
  int N, D;
  cin >> N >> D;
  
  D = D * D;
  
  int ans = 0;
  
  for(int i=0;i<N;i++){

    int X, Y;
    cin >> X >> Y;
      
    int d = X * X + Y * Y;
    
    if( d <= D ) ans++;
    
  }
  
  cout << ans << endl;
  
  return 0;
}
