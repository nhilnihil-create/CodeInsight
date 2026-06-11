#include <iostream>
using namespace std;

int main()
{
  long long n, a, b;
  cin >> n >> a >> b;
  if(a + b == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  
  long long cnt = (n / (a + b)) * a;
  cnt += (n % (a + b) >= a) ? a : n % (a + b);
  cout << cnt << endl;
  return 0;
}