#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N;
  cin >> N;
  
  if (N % 2 == 1){
    cout << 0 << endl;
    return 0;
  }
  
  long long ans = 0;
  N /= 10;
  ans += N;
 
  for (int i = 0; i < 30; i++) {
    N /= 5;
    ans += N;
    if (N == 0){
      cout << ans << endl;
      return 0;
    }
  }
}
    
    
    