#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    long long x; cin >> x;
    long long a, b, a_5, b_5;
    for (a = 1; a < 1000; a++)
    {
        a_5 = pow(a, 5);
        if (a_5 > x)
        {
            for (b = 0; b < 1000; b++)
            {
                b_5 = pow(b, 5);
                if (a_5 - b_5 == x)
                {
                    cout << a << " " << b << endl;
                    return 0;
                }
            }
        }
        else
        {
            for (b = 0; b < 1000; b++)
            {
                b_5 = - pow(b, 5);
                if (a_5 - b_5 == x)
                {
                    cout << a << " " << -b << endl;
                    return 0;
                }
            }
        }
    }
}