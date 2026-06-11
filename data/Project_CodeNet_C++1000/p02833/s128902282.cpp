#include <bits/stdc++.h>
using namespace std;
    
int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  if (N%2 == 1)
    cout << 0 << endl;
  
  else {
    long long A = 10;
    while (A <= N) {
      ans += N/A;
      A *= 5;
    }
    cout << ans << endl;
  }
}
