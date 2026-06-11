#include <iostream>
#include <vector>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;

    int ret = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) for (int k = 0; k < j; k++) {
        if (a[i] == a[j] || a[j] == a[k] || a[k] == a[i]) continue;
        if (a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[k] + a[i] > a[j]) ret++;
    }

    std::cout << ret << std::endl;

    return 0;
}
