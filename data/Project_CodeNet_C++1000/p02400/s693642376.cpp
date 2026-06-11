#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
main()
{
    double r,area,circum;
    cin >> r;
    area = r*r*M_PI;
    circum = 2*r*M_PI;
    cout << fixed << setprecision(6)<< area << " " << circum << endl; 
    return 0;
}