#include <cmath>
#include <iostream>
#include <vector>

int cnt = 0;

void insertionsort(std::vector<int> &v, int n, int g) {
    int elem = 0;
    int j = 0;
    for (int i = g; i < n; i++) {
        elem = v[i];
        j = i - g;
        while ((j >= 0) && (v[j] > elem)) {
            v[j + g] = v[j];
            j -= g;
            cnt++;
        }
        v[j + g] = elem;
    }
}

void shellsort(std::vector<int> &v, int n) {
    const int m = 13;

    std::vector<int> g(m);
    for (int i = 0; i < m; i++) {
        g[i] = (pow(3, i+1) - 1) / 2;
    }

    int tail = m - 1;
    while (tail > 0 && g[tail] > n) tail--;
    std::cout << tail+1 << std::endl;
    for (int i = tail; i > 0; i--) {
        std::cout << g[i] << " ";
    }
    std::cout << g[0] << std::endl;

    for (int i = tail; i >= 0; i--) {
        insertionsort(v, n, g[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    shellsort(v, n);
    std::cout << cnt << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}