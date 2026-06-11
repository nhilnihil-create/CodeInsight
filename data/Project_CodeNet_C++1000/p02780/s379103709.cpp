#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using ll = long long;
using lli = long long int;

int n, k, p;
std::vector<int> vec;
int max_value;

int main() {
    max_value = 0;
    std::cin >> n >> k;
    vec.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> p;
        p++;
        vec[i] = vec[i-1] + p;
    }
    for (int i = 0; i+k <= n; i++) {
        if (max_value < vec[i+k]-vec[i])
            max_value = vec[i+k] - vec[i];
    }
    std::cout << std::fixed << std::setprecision(10) << ((long double)max_value / 2.0) << std::endl;
}
