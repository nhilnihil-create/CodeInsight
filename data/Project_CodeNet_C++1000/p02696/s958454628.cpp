#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  
  
  long long ans = 0, x = n;
    if(n >= b-1) x = b-1;
    ans = floor(a*x / b) - a*floor(x/b);
    
  cout << ans << endl;
}
