#include <iostream>

int main()
{
    int n, m, l;
    std::cin >> n >> m >> l;

    int a[n][m] = {};
    int b[m][l] = {};
    long int c[n][l] = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            std::cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int f = 0; f < m; f++) {
                c[i][j] += a[i][f] * b[f][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << c[i][j];
            if (j == l - 1) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }

        }
    }

    return 0;
}