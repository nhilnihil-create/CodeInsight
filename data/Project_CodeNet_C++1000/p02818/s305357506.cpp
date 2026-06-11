#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a, b, k;
  cin >> a >> b >> k;
  if (a >= k)
  {
    cout << a - k << " " << b << endl;
  }
  else if (b >= k - a)
  {
    cout << 0 << " " << b - k + a << endl;
  }
  else
  {
    cout << 0 << " " << 0 << endl;
  }
}
