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
    int n;
    cin >> n;
    int ans = 0;
    int l = log10(n);
    if (l % 2 == 1)
    {
        l--;
    }
    else
    {
        ans += n - pow(10, l) + 1;
        l -= 2;
    }
    while (l >= 0)
    {
        ans += pow(10, l + 1) - pow(10, l);
        l -= 2;
    }
    cout << ans << endl;
    return 0;
}