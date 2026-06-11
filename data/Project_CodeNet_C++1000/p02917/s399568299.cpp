#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int b[n-1];
  for (int i = 0; i < n-1; i++) {
    cin >> b[i];
  }
  long long ans = b[0];
  for (int i = 1; i < n-1; i++) {
    ans += min(b[i-1], b[i]);
  }
  ans += b[n-2];
  cout << ans << endl;
  return 0;
}