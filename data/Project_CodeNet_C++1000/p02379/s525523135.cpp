#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
 
int main()
{
    double sq, x1, y1, x2, y2;
 
    cin >> x1 >> y1 >> x2 >> y2;
 
    sq = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    sq = sqrt(sq);
 
    printf("%.6f\n", sq);
 
    return 0;
}