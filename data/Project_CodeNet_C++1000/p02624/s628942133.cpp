#include <iostream>
using namespace std;

int main() {
  long n;
  cin >> n;
  
  long long ans = 0;
  for (int i=1; i <= n; ++i) {
    for (int j=i; j<=n; j+=i) {
      if (j%i==0) ans += j;
    }
  }
  cout << ans << endl;
  
  return 0;
}
