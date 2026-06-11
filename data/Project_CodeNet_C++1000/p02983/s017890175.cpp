#include <bits/stdc++.h>
using namespace std;

int main() {
  long long L, R;
  cin >> L >> R;
  int mod = 2019;
  long long ans = 10000000;
  for(long long i = L; i < R && i < L+2019;i++){
    for(long long j = L+1; j <= R && j <=L+ 2019;j++){
      ans = min(ans, i*j%mod);
    }
  }
  cout << ans << endl;
}
