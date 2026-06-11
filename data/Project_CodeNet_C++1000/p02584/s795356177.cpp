#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, k, d;
  cin >> x >> k >> d;
  
  x = abs(x);
  if(x/d>=k) cout << x-k*d << endl;
  else if((k-x/d)%2==0) cout << x%d << endl;
  else if(x%d-d<=0) cout << abs(x%d-d) << endl;
  else cout << x%d+d << endl;
  
  return 0;
}
