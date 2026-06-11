#include <bits/stdc++.h>
using namespace std;

int my_gcd(int x, int y) {
    if (x < y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int res;
    while (y > 0) {
        res = x % y;
        x = y;
        y = res;
    }
    return x;
}

int main() {
    int k;
    cin >> k;

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                sum += my_gcd(my_gcd(i, j), l);
            }
        }
    }

    cout << sum << endl;

    return 0;
}
