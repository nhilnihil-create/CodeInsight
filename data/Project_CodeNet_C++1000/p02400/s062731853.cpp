#include <iostream>
using namespace std;
 
int main()
{
double r, area, circle;
cin >> r;
area = r * r * 3.141592653589;
circle = 2 * r * 3.141592653589;
cout << fixed << area << " " << circle << endl;
return 0;
}