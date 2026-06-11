#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    long a, b, v, w;
    long t;
    cin >> a >> v >> b >> w >> t;

    long distance = (a > b) ? a - b : b - a;
    long diff_v = (v - w) * t;

    if (distance <= diff_v)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}