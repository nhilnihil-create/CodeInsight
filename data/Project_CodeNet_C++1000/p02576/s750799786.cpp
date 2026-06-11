#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x,n,t,ans;
  cin >> n >> x >> t;
  
  ans = (n+x-1)/x;
  cout << ans *t << endl;
  
}