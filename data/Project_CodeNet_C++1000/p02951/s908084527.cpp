# include <iostream>
using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;
  int ans = c - a + b;
  if (ans > 0) cout << ans << endl;
  else cout << 0 << endl;
  
  return 0;
}