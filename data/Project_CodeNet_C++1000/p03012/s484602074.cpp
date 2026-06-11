#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    int ave = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }

    std::vector<int> di;
    for (int t = 1; t <= n - 1; t++)
    {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(i < t) {
                s1 += w[i];
            } else {
                s2 += w[i];
            }
        }

        di.push_back(std::abs(s1-s2));
    }

    std::cout << *std::min_element(di.begin(), di.end()) << "\n";
}
