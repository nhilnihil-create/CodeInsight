#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    long long int a, b, k;
    cin >> a >> b >> k;
    if (a > k)
    {
        a = a - k;
    }
    else if (a + b > k)
    {
        b = b - k + a;
        a = 0;
    }
    else
    {
        a = 0;
        b = 0;
    }

    cout << a << " " << b << endl;
    return 0;
}