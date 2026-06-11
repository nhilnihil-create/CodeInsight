#include <iostream>
#include <map>
#include <cmath>

using ll = long long;

ll n;

std::map<ll, ll> mapa;
long heights[2000001];

int main() {
    std::cin >> n;
    ll solutions = 0;
    for (ll i = 0, tmp; i < n; ++i) {
        std::cin >> tmp;
        mapa[tmp + i] += 1;
        heights[i] = tmp;
    }
    for (ll i = 0; i < n; ++i) {
        if ((i - heights[i]) >= 0)
        solutions += mapa[i - heights[i]];
    }
    std::cout << solutions;
    return 0;
}