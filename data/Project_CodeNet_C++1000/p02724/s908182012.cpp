#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X,ans=0; cin >> X;
  
  while(X>=500) {
    X -= 500;
    ans += 1000;
  }
  while(X>=5) {
    X -= 5;
    ans += 5;
  }
  cout << ans << endl;
}