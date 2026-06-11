#include <iostream>
#include <string>
using i64 = long long;

int main() {
    std::string s, t;
    std::cin >> s >> t;
    const int n = s.size(), m = t.size();

    int ret = n;
    for (int i = 0; i + m <= n; i++) {
        int c = 0;
        for (int j = 0; j < m; j++) if (s[i + j] != t[j]) c++;
        if (ret > c) ret = c;
    }

    std::cout << ret << std::endl;

    return 0;
}
