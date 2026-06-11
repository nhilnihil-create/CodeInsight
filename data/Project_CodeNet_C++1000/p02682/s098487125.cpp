#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a,b,c,k;
  cin >> a >> b >> c >> k;
  int64_t ans;
  
  if(a>k)
    ans = k;
  
  else{
    if(a+b > k)
      ans = a;
    else if (a+b+c <k)
      ans = a-c;
    else
      ans = a - (k-a-b);
  }
  cout << ans << endl;
}