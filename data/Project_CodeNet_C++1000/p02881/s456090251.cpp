#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;
  cin >> n;
  long long ans = n;
  for (long long i = 1;i*i <= n;i++){
    long long x = n / i;
    if (n % x == 0){
      long long c = x + i;
      ans = min(ans, c-2);
    }
  }
  
  cout << ans << endl;
}