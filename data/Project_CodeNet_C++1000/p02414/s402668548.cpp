#include <iostream>
 
int main(int argc, const char * argv[]) {
    int n, m, l;
    std::cin >> n >> m >> l;
    int a[n][m] = {}, b[m][l] = {};
    long long c[n][l] = {};
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
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << c[i][0];
        for (int j = 1; j < l; j++) {
            std::cout << " " << c[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}