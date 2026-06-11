#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (((x2-x1)==0) && ((x4-x3)==0))
            cout << "YES" << endl;
        else {
            double d = abs((y2-y1)*(x4-x3) - (y4-y3)*(x2-x1));
            cout << ((d <= 1e-10)? "YES" : "NO") << endl;
        }
    }
    return 0;
}

