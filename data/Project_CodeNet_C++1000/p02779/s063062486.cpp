#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> nums;
    for (int i = 0, tmp; i < n; ++i) {
        std::cin >> tmp;
        nums.insert(tmp);
    }
    if (nums.size() == n) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}