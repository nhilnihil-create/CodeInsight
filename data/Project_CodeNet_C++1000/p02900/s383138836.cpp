#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>

T calcgcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y);
    }
    T r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

vector<pair<ll, ll>> PrimeFactorization(long long n)
{
    vector<pair<ll, ll>> res;
    for(long long i = 2; i * i <= n; ++i)
    {
        if (n % i) continue;
        res.emplace_back(i, 0);
        while (n % i == 0)
        {
            ++res.back().second;
            n = n / i;
        }
    }
    if (n != 1)
    {
        res.emplace_back(n, 1);
    }
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = calcgcd(a, b);

    auto res = PrimeFactorization(g);

    ll ans = res.size() + 1;
    cout << ans << endl;
    return 0;
}
