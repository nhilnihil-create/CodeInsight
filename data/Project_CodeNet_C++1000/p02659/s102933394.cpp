#include <bits/stdc++.h>
#define ll long long
#define ld long double
int main()
{
    ll a;
    ld b;
    ll c;
    ll temp_l;
    ld temp_d;
    ll temp_k;
    ll ans;
    std::cin >> a >> b;
    //temp_d = std::floor(b);
    //b = b - temp_d;
    b *= 100ll;
    c = std::round(b);
    //temp_l = static_cast<ll>(temp_d);
    //temp_k = static_cast<ll>(b);
    ans = (a * c) / 100ll;
    std::cout << ans << std::endl;
}