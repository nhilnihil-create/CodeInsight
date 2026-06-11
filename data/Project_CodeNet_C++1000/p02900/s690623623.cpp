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

bool PrimeFactorization(long long n, std::map<long long, long long>& mp)
{
    if (n <= 1) return false;
    long long num = n;
    for(long long i = 2; i * i <= n; ++i)
    {
        long long r = num % i;
        while (r == 0)
        {
            ++mp[i];
            num = num / i;
            r = num % i;
        }
    }
    // 割り続けて1とならない場合,
    // numはまだ出ていない素数となる(あるいはnそのものが素数である)
    // したがって、これもカウントする
    if (num != 1)
    {
        ++mp[num]; // dic[num] = 1 でも OK 
    }
    return true;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = calcgcd(a, b);
    map<ll, ll> res;
    PrimeFactorization(g, res);

    ll ans = res.size() + 1;
    cout << ans << endl;
    return 0;
}
