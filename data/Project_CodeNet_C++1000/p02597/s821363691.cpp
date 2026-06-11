#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
char c[200005];

signed main(){
  
  cin >> N;
  
  for(int i=0;i<N;i++) cin >> c[i];
  
  int L = 0, R = N - 1;
  int ans = 0;
  
  while( L < R ){
    
    if( c[L] == 'W' && c[R] == 'R' ){
      L++;
      R--;
      ans++;
    }
    else if( c[L] == 'W' ) R--;
    else if( c[R] == 'R' ) L++;
    else L++, R--;    
    
  }

  cout << ans << endl;
  
  return 0;
}
