#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    double dis = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    cout << setprecision(10);
    cout << dis << endl;
    return 0;
}