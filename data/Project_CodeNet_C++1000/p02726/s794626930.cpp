#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using lli = long long int;

lli n, x, y;
std::vector<std::vector<lli>> vec;
std::vector<lli> answers;

int main() {
    std::cin >> n >> x >> y;
    answers.assign(n, 0);
    lli s = x + y;
    vec.assign(n+1, std::vector<lli>(n+1, -1));
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            if (i == j) {
                vec[i][j] = 0;
                continue;
            }
            if (vec[j][i] != -1) {
                vec[i][j] = vec[j][i];
                continue;
            }
            lli direct_distance = std::abs(i - j);
            lli warp_distance;
            lli near_whole = (std::abs(i-x) <= std::abs(i-y) ? x : y);
            lli warp_dst = s - near_whole;
            warp_distance = std::abs(i-near_whole) + 1 + std::abs(j-warp_dst);
            lli res = std::min(direct_distance, warp_distance);
            vec[i][j] = res;
            answers[res]++;
        }
    }
    for (int i = 1; i < n; i++) {
        std::cout << answers[i] << std::endl;
    }
}
