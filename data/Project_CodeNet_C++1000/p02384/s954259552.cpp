#include <iostream>
int main() {
    int m[7][7] = {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 3, 5, 2, 4, 0 },
        { 0, 4, 0, 1, 6, 0, 3 },
        { 0, 2, 6, 0, 0, 1, 5 },
        { 0, 5, 1, 0, 0, 6, 2 },
        { 0, 3, 0, 6, 1, 0, 4 },
        { 0, 0, 4, 2, 5, 3, 0 }
    }, a[101], b[7], n, t, f;
    for (int i = 1; i <= 6; ++i) {
        std::cin >> n;
        a[n] = i;
        b[i] = n;
    }
    std::cin >> n; // skip
    while (std::cin >> t >> f) {
        std::cout << b[m[a[t]][a[f]]] << std::endl;
    }
}

