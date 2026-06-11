#include <bits/stdc++.h>

using ll = int64_t;

int main() {
    ll S;
    std::cin >> S;

    const ll v = 1000000000;

    const ll Y2 = (v - S % v) % v;
    const ll Y3 = (S + Y2) / v;

    std::printf("%d %d %ld %ld %d %ld\n", 0, 0, v, Y2, 1, Y3); 

    return 0;
}
