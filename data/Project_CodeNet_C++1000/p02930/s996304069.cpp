#include <bits/stdc++.h>
using i64 = long long;


int main() {
    int ret[500][500];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        for (int k = 0; k < 10; k++) {
            if ((i & (1 << k)) ^ (j & (1 << k))) {
                ret[i][j] = ret[j][i] = k + 1;
                break;
            }
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) std::cout << ret[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
