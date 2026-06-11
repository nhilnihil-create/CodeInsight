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
    int in;
    cin >> in;
    
    cout << (in * in) << endl;
    return 0;
}