#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
    long long x, k, d, m, y;
    m = 0;
    cin >> x >> k >> d;
    y = abs(x);
    if (y > 0)
    {
        /*      while ((y - (m + 1) * d) > 0 && m < k)
        {
            m++;
        }
        */
        m = min(k, y / d);
        if ((k - m) % 2 == 0)
        {
            cout << abs(y - m * d) << endl;
        }
        else
        {
            cout << abs(y - (m + 1) * d) << endl;
        }
        return 0;
    }
    if (y == 0)
    {
        if (k % 2 == 1)
        {
            cout << d << endl;
        }
        else
        {

            cout << "0" << endl;
        }
        return 0;
    }
    return 0;
}