#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    double x1, y1, x2, y2;
    double d;

    cin >> x1 >> y1 >> x2 >> y2;
    
    d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

    cout << std::fixed << std::setprecision(8) << d << endl;

    return 0;
}
