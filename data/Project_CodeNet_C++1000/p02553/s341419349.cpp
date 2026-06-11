#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    long long a, b, c, d;
    long long e[4], max;
    int i = 0;
    cin >> a >> b >> c >> d;
    e[0] = a * c;
    e[1] = a * d;
    e[2] = b * c;
    e[3] = b * d;
    max = e[0];
    for (i = 1; i < 4; i++)
    {
        if (max < e[i])
        {
            max = e[i];
        }
    }
    cout << max << endl;
    return 0;
}