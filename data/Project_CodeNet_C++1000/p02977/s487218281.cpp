#include "bits/stdc++.h"
using namespace std;
typedef long long li;

void put(li fr, li to) {
    cout << fr << " " << to << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;

    if (__builtin_popcountll(n) == 1) {
        cout << "No" << endl;
    } else if (n % 4 == 3) {
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * n - 1; ++i) {
            put(i + 1, i + 2);
        }
    } else if (n % 4 == 1) {
        cout << "Yes" << endl;
        for (int i = 1; i < n - 2; ++i) {
            put(i, i + 1);
            put(n + i, n + i + 1);
        }
        put(n - 2, n + 1);

        put(n - 1, n);
        put(n, 1);
        put(1, n - 1 + n);
        put(n - 1 + n, n + n);
    } else if (n % 4 == 2) {
        cout << "Yes" << endl;
        for (int i = 1; i < n - 3; ++i) {
            put(i, i + 1);
            put(n + i, n + i + 1);
        }
        put(n - 3, n + 1);

        put(n - 2, n - 1);
        put(n - 1, 1);
        put(1, n - 2 + n);
        put(n - 2 + n, n - 1 + n);
        put(n, n - 1);
        put(2, n + n);
    } else { // n % 4 == 0
        cout << "Yes" << endl;
        for (int i = 1; i < n - 1; ++i) {
            put(i, i + 1);
            put(n + i, n + i + 1);
        }
        put(n - 1, n + 1);

        const li shiftv = 1LL << __builtin_ctzll(n);
        const li fr = n - shiftv + 1;
        const li to = shiftv;
        put(n, fr);
        put(to + n, n + n);
    }

    return 0;
}