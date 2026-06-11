#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  
  long long ans=n;
  ans %= k;
  ans = min(ans, k-ans);
   
  
  cout << ans << endl;
    
}
  
