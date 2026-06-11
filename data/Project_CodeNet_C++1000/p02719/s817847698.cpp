#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int a, b;
  cin >> a >> b;
  cout << min(abs((a % b) - b), (a % b)) << '\n';
  return 0;
}
