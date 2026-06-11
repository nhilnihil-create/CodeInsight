#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
 const double PI = 3.141592653589;
 double r;
 double area, circle;
 cin >> r;
 area = r * r * PI;
 circle = 2 * r * PI;
 cout << fixed << setprecision(5) << area << " " << circle << endl;
}
