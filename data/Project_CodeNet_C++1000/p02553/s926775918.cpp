#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  long long a, b, c, d, x, y, ans;
  cin >> a >> b >> c >> d;
  
  x=max(a, b);
  y=max(c, d);
  
  
  ans = max(x*y,min(a, b)*min(c, d));
  ans = max(ans,min(a, b)*max(c, d));
  ans = max(ans,max(a, b)*min(c, d));        
  
  cout << ans;
} 