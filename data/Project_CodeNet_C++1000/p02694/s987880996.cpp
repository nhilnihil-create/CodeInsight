#include <iostream>
using namespace std;

int main()
{
  long long x, yen = 100, ans = 0;
  cin >> x;
  while(yen < x)
  {
    yen += yen / 100;
    ans++;
  }
  
  cout << ans << endl;
  return 0;
}