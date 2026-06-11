#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using ll = long long int;
using namespace std;

int main()
{
    int X, Y, ans = 0;
    cin >> X >> Y;
    if (X == 1)
    {
        ans += 300000;
    }
    else if (X == 2)
    {
        ans += 200000;
    }
    else if (X == 3)
    {
        ans += 100000;
    }
    if (Y == 1)
    {
        ans += 300000;
    }
    else if (Y == 2)
    {
        ans += 200000;
    }
    else if (Y == 3)
    {
        ans += 100000;
    }
    if ((X == 1) && (Y == 1))
    {
        ans += 400000;
    }
    cout << ans << endl;

    return 0;
}