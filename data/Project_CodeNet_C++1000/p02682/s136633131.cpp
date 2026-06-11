#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b, c, k; cin >> a >> b >> c >> k;
  int ans;
  if (a >= k){ans=k;}
  else if (a<k && a+b>=k){ans=a;}
  else {ans=2*a+b-k;}
  cout << ans << endl;
}