#include <iostream>
using namespace std;
 
int main()
{
    int n, x, t;
    int res;
    cin >> n >> x >> t;
    res = (n/x)*t;
    if (n % x > 0)
      res += t;
    cout << res;
}
