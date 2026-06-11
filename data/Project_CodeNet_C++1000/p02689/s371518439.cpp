#include <iostream>
#include <vector>
#include <algorithm>

using lli = long long int;
using ll = long long;

lli n, m, h, a, b;

std::vector<lli> vec;
std::vector<lli> viewpoints;

int main() {
    std::cin >> n >> m;
    vec.assign(n+1, 0);
    viewpoints.assign(n+1, -1);
    for (int i = 1; i <= n; i++) {
        std::cin >> vec[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        if (vec[a] <= vec[b]) {
            viewpoints[a] = 0;
        }
        if (vec[b] <= vec[a]) {
            viewpoints[b] = 0;
        }
    }
    lli ans = std::count(viewpoints.begin()+1, viewpoints.end(), -1);
    std::cout << ans << std::endl;
}
