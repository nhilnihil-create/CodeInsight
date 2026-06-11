#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int fact[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
    int order[9];

    int n; cin >> n;
    int porder = 0, qorder = 0;

    for (int i = 0; i <= n; ++i) order[i] = i;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        porder += fact[n - i - 1] * (order[a] - 1);
        for (int j = a + 1; j <= n; ++j) --order[j];
    }
    ++porder;

    for (int i = 0; i <= n; ++i) order[i] = i;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        qorder += fact[n - i - 1] * (order[a] - 1);
        for (int j = a + 1; j <= n; ++j) --order[j];
    }
    ++qorder;

    cout << abs(porder - qorder) << endl;
}

