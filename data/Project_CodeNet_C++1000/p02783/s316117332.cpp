#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,A;
  cin >> H >> A;
  int ans = 0;
  while(1){
    ans ++;
    H -= A;
    if(H <= 0) break;
  }
  cout << ans << endl;
  
}