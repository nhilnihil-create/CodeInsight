#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main(int argc, char const* argv[])
{
    unsigned n;
    std::cin >> n;
    while (n!=0) {
        double sum{};
        double sigma{};
        double m{};
        std::vector<int> ss;
        for (int i = 0; i < n; i++) {
            int s;
            std::cin >> s;
            ss.push_back(s);
        }
        sum = 0.;
        for (auto&& s : ss) {
            sum += s;
        }
        m = sum / n;
        for (auto&& s : ss) {
            sigma += (s - m) * (s - m);
        }
        std::cout << std::fixed <<std::setprecision(8) << std::sqrt(sigma/n) << std::endl;
        std::cin >> n;
    }

    return 0;
}