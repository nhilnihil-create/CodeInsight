#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  
  int64_t num = 0, ans = 1000000000001;
  for(int i=1; i<=sqrt(n); i++) {
    if(n%i==0) num = (i-1)+(n/i-1);
    ans = min(num, ans);
  }
  
  cout << ans << endl;
  return 0;
}