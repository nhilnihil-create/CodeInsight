#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int cnt = 0;
int m   = 0;
std::vector<int> g;

void insertionSort(int a[], int n, int g)
{
    for (int i = g; i < n; ++i) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }
}

void shellSort(int a[], int n)
{

    int v = 1;
    while (true) {
        g.push_back(v);
        v *= 4;
        if (n <= v) {
            break;
        }
    }

    m = g.size();

    for (int i = 0; i < m; ++i) {
        insertionSort(a, n, g[m - 1 - i]);
    }

}

int main()
{
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    shellSort(a, n);

    std::cout << m << std::endl;

    for (int i = 0; i < m; ++i) {
        std::cout << g[m-1-i];
        if (i == (m-1)) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    std::cout << cnt << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
