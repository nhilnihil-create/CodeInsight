#include <iostream>
#include <vector>
#include <map>

int n;
int t;

std::map<int, int> m;

int main() {
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> t;
        m[t]++;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << m[i] << std::endl;
    }
}