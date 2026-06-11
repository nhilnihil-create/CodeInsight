#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k, ans;
  cin >> n >> k;
  ans=n+2-k+(n+1)*((n+1)*(n+2)/2-(k-1)*k/2)-(n+1)*(n+2)*(2*n+3)/6+(k-1)*k*(2*k-1)/6;
  ans%=((int)pow(10, 9)+7);
  cout << ans;
  return 0;
}
