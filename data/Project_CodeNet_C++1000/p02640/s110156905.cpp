//time:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    /***
    a=y/2-x
    b=2x-y/2
    4a+2b=y
    a+b=x
    ***/
    int a, b;
    a = y / 2 - x;
    b = 2 * x - y / 2;
    if (a < 0 || b < 0 || y % 2 == 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}