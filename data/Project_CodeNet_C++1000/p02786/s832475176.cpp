#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >> n;
  
  long long times = 0;
  long long ans = 0;
  while(n > 0) {
  	ans += pow(2, times);
    times++;
    n /= 2;
  }
  cout << ans << endl;

  return 0; 
}