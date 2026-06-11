#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
int main()
{
    ll x, y, i, num = 0;
    cin >> x;
    for (i = sqrt(x); i > 0; --i)
    {
        y = x / i;
        if (y * i == x)
            break;
    }
    cout << y + i - 2 << endl;
}