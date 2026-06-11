#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// 最大公約数
ll GCD(ll a, ll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

// 最小公倍数
ll LCM(ll a, ll b)
{
    ll g = GCD(a, b);
    return a / g * b;
}

int main()
{
    string in;
    cin >> in;
    int ret = 0;
    if (in == "SUN")
    {
        ret = 7;
    }
    if (in == "MON")
    {
        ret = 6;
    }
    if (in == "TUE")
    {
        ret = 5;
    }
    if (in == "WED")
    {
        ret = 4;
    }
    if (in == "THU")
    {
        ret = 3;
    }
    if (in == "FRI")
    {
        ret = 2;
    }
    if (in == "SAT")
    {
        ret = 1;
    }

    cout << ret << endl;
    return 0;
}