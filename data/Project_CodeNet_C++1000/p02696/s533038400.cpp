#include <iostream>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  long long x = b - 1;
  if (n < b - 1) x = n;
  long long ans = (a*x/b) - a*(x/b);
  cout << ans << endl;
  return 0;
}