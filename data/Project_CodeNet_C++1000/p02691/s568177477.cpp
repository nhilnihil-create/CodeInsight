#include <iostream>
#include <map>

using ll = long long;

ll n;

std::map<ll, ll> mapa;

int main() {
    std::cin >> n;
    ll solutions = 0;
    for (ll i = 0, tmp; i < n; ++i) {
        std::cin >> tmp;
        solutions += mapa[i - tmp];
        mapa[i + tmp] += 1;
    }
    std::cout << solutions;
    return 0;
}