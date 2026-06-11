#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double x = (x1-x2);
    double y = (y1-y2);

    double l = sqrt(x*x + y*y);
    printf("%.8f\n", l);

}
