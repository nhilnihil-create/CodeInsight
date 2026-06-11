#include <bits/stdc++.h>

using ll = long long;

int main(){
    ll x, k, d;
    scanf("%lld%lld%lld", &x, &k, &d);
    if (x + __int128(k) * d <= 0){
        printf("%lld\n", std::abs(x + k * d));
        return 0;
    }
    if (x - __int128(k) * d >= 0){
        printf("%lld\n", std::abs(x - k * d));
        return 0;
    }
    if (k == 1){
        printf("%lld\n", std::min(std::abs(x + d), std::abs(x - d)));
        return 0;
    }
    if (k & 1){
        x += d;
    }
    x = x % (2 * d);
    x += x < 0 ? 2 * d : 0;
    printf("%lld\n", std::min(x, std::abs(x - 2 * d)));
    return 0;
}