#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,ans;
  cin >> n >> k;
  ans = 1;
  while(true){
    if(n/k > 0){
      n /= k;
      ans++;
    }
    else
      break;
  }
  cout << ans << endl;
}