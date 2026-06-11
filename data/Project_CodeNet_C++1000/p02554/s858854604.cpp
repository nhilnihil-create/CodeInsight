#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
const ll mod = 1000000007;

ll ruijo(ll x, ll n) {
    ll tmp = 1;
    while(n)
    {
        if(n&1) tmp = tmp * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return tmp;
}

int main()
{
    ll N;
    std::cin >> N;

    // 条件なし 10^N
    // 0を1個以上含む 含まないのは 9^N
    ll ans = 0;
    ans += ruijo(10, N);
    ans -= 2 * ruijo(9, N);
    ans += ruijo(8, N);
    ans = (ans % mod + mod) % mod;
    std::cout << ans << std::endl;
}