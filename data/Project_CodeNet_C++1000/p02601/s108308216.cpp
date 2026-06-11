#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

#define intt long long
#define PI 3.14159265358979323846

using Graph = std::vector<std::vector<intt>>;
Graph G;

int main() {
    intt A, B, C, K; std::cin >> A >> B >> C >> K;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K - i; ++j) {
            if (A * std::pow(2, i) < B * std::pow(2, j) && B * std::pow(2, j) < C * std::pow(2, K-j)) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}