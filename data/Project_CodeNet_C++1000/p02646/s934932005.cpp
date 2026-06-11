#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int64_t a, b, v, w, t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;

  int64_t ba = abs(b - a);
  int64_t wv = w - v;

  if (wv > 0)
  {
    cout << "NO" << endl;
    return 0;
  }

  double ti = 1 / (double)t;
  if (wv <= -ba * ti)
  {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
  return 0;
}