#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n; std::cin >> n;
    std::string buf = "";
    auto func = [&](auto &self, char last = 'a') {
        if (buf.size() >= n) {
            std::cout << buf << std::endl;
            return;
        }
        for (char c = 'a'; c <= last; c++) {
            buf.push_back(c);
            self(self, last + (c == last));
            buf.pop_back();
        }
    };
    func(func);
    return 0;
}
