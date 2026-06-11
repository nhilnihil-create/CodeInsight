// https://atcoder.jp/contests/abc175/tasks/abc175_c
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <iterator> // std::back_inserter

using namespace std;

int main()
{
    long long x, k, d;

    cin >> x >> k >> d;
    x = abs(x);
    long long mod = x % d;
    long long div = x / d;
    long long a = x - mod;
    if (k < x / d)
    {
        cout << x - (d * k) << endl;
    }
    else if ((k - div) % 2 == 0)
    {
        cout << x - a << endl;
    }
    else
    {
        cout << d - (x - a) << endl;
    }
}
