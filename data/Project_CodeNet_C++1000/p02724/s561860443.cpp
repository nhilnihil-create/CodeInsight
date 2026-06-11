#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int money;
  cin >> money;
  cout << (money / 500) * 1000 + ((money % 500) / 5) * 5 << '\n';
  return 0;
}
