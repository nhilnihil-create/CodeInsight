#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d,ans;
  cin >> n >> d;
  if(n%(2*d+1)==0) ans = n/(2*d+1);
  else ans = n/(2*d+1)+1;
  cout << ans << endl;
}