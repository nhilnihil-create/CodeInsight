#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    long long x;
    cin >> x;
    long long m = 100;
    long long i = 0;
    for (i = 0; m < x; i++)
    {
        m += m / 100;
    }
    cout << i << endl;
    return 0;
}
