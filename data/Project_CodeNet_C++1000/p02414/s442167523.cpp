#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
    int n, m, l;
    std::cin >> n >> m >> l;

    int a[n][m] = {};
    int b[m][l] = {};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < l; ++j) {
            std::cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            long c = 0;
            for (int k = 0; k < m; ++k) {
                c += a[i][k] * b[k][j];
            }
            std::cout << c;
            if (j != (l - 1)) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}
