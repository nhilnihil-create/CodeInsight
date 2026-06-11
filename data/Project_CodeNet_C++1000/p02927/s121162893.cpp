#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int M, D;
  cin >> M >> D;
  
  int count = 0;
  for( int i = 1; i <= M; i++ ){
    for( int j = 10; j <= D; j++ ){
      int A = j%10;
      int B = j/10;
      if( i == A*B && A >= 2 && B >= 2 ){
        count++;
      }
    }
  }
  cout << count << endl;
  
  
    
}