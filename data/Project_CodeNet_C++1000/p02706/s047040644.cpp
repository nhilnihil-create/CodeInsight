#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[m] = {};
    for (auto i = 0; i < m; i++) cin >> a[i];

    cout << max(-1, n - accumulate(a, a + m, 0));
}