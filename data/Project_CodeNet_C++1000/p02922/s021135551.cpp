#include <iostream>
using namespace std;
int main()
{
  int a, b; cin >> a >> b;
  int ans = 0;
  while (true)
  {
    if (1 + (a - 1) * ans >= b) break;
    else ans++;
  }
  cout << ans << endl;
}