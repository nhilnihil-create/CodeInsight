#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    queue<int> c;
    for (int i = 0; i < n; i++) {
        c.push(i);
    }

    ll r = 0;
    while (!c.empty()) {
        int i = c.front(); c.pop();
        int i1 = i - 1; if (i1 < 0) i1 += n;
        int i2 = i + 1; if (i2 >= n) i2 -= n;
        int s = b[i1] + b[i2];
        int t = b[i] - a[i];
        if (t >= s) {
            int x = t / s;
            b[i] -= x * s;
            r += x;
            c.push(i1);
            c.push(i2);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) r = -1;
    }

    cout << r << endl;

    return 0;
}