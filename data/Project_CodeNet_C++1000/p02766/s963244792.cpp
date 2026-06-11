#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  int x = 1;
  int ans = 0;
  
  if ( n == 1){
    ans = 1;
  }
  else{
    while (x <= n){
      x *= k;
      ans++;
    }
  }
  
  cout << ans << endl;
}