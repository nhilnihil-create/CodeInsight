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

    string s;
    cin >> s;

    int b = 2;
    for (int i = 0; i < n; i++) {
        s[i] -= '1';
        if (s[i] == 1) b = 1;
    }

    auto f = [](int i) {
        int k = 0;
        while (i % 2 == 0) i /= 2, k++;
        return k;
    };

    int r = 0, x = 0;
    for (int i = 0; i < n; i++) {
        r ^= (s[i] == b && x == 0);
        if (i < n - 1) x += f(n - 1 - i) - f(i + 1);
    }

    cout << r * b << endl;

    return 0;
}