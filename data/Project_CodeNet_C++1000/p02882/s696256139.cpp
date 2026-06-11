#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  int a, b, x;
  cin >> a >> b >> x;

  if (x > a * a * b / 2)
  {
    double at = 2 * double(a * a * b - x) / pow(a, 3);

    double theta = atan(at);
    theta = theta * 180 / M_PI;

    cout << fixed << setprecision(10) << theta << endl;
  }
  else
  {
    double at = a * b * b / double(2 * x);

    double theta = atan(at);
    theta = theta * 180 / M_PI;

    cout << fixed << setprecision(10) << theta << endl;
  }

  return 0;
}