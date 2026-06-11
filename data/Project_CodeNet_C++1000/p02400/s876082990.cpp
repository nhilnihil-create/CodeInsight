#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    double r;
    // scanf("%d %d",r);
    cin >> r;
    const double pi = 3.141592653589793;
    // cout<< M_PI<<endl;
    printf("%.6f %.6f\n", double(pi*r*r), double(2*pi*r));
    return 0;

}
