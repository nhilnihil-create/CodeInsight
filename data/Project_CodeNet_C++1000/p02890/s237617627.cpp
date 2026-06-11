#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;

        b[a]++;
    }

    vector<int> c(n + 1);
    for (int i = 0; i < n; i++) {
        c[b[i]]++;
    }

    int n1 = n, m1 = 0, k = 1;
    for (int h = n; h >= 0; h--) {
        int k1 = h > 0 ? n1 / h + m1 : n;
        for (; k <= k1; k++) {
            cout << h << '\n';
        }
        n1 -= c[h] * h;
        m1 += c[h];
    }

    return 0;
}