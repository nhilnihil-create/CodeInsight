#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k; cin >> n >> k;
  long long foo = n / k;
  long long ans = n - (k * foo);

  while(true) {
    long long current = abs(ans - k);
    if(ans < current){
      break;
    } else {
      ans = current;
    }
  }
  
  cout << ans << endl;
  
  
  return 0; 
}

// abs(a,b ) -> absolute