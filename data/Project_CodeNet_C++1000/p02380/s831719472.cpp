#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a, b, C;  // side length 1, side length 2, internal angle (deg)
  cin >> a >> b >> C;

  double height = b*sin(C*M_PI/180);
  double area = 0.5*a*height;

  double opp = sqrt(pow(height, 2) + pow(a - (b*cos(C*M_PI/180)), 2));

  double perimeter = a + b + opp;

  cout << fixed << area << " " << perimeter << " " << height << endl;
}
