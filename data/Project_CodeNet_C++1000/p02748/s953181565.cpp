#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll A, B, M; std::cin >> A >> B >> M;
    std::vector<ll> a, b;
    ll min_a=1145141919, min_b=1145141919;
    for(int i=0; i<A; i++){
        ll buf; std::cin >> buf;
        a.push_back(buf); min_a=std::min(min_a, buf);
    }
    for(int i=0; i<B; i++){
        ll buf; std::cin >> buf;
        b.push_back(buf); min_b=std::min(min_b, buf);
    }

    ll ans = min_a + min_b;

    for(int i=0; i<M; i++){
        ll x, y, c; std::cin >> x >> y >> c;
        ans = std::min(ans, a[x-1] + b[y-1] - c);
    }

    std::cout << ans;
    return 0;
}
