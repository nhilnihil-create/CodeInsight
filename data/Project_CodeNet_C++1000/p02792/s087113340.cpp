#include <bits/stdc++.h>
using namespace std;

template <typename T>
T ipow(T b, long long e) {
    if (e == 0) {
        return 1;
    } else if (e % 2 == 0) {
        return ipow(b * b, e / 2);
    } else {
        return ipow(b * b, e / 2) * b;
    }
}

int digit_number_10(long long n) {
    for (int i = 1;; i++) {
        if (n < ipow(10, i)) {
            return i;
        }
    }
}

int main() {
    long long N, ans = 0;
    cin >> N;
    int c[10][10];
    for (int l = 1; l <= 9; l++) {
        for (int r = 1; r <= 9; r++) {
            c[l][r] = 0;
            for (int X = 1; X <= N; X++) {
                if (X % 10 == r && X / ipow(10, digit_number_10(X) - 1) == l) {
                    c[l][r]++;
                }
            }
        }
    }
    for (int l = 1; l <= 9; l++) {
        for (int r = 1; r <= 9; r++) {
            ans += c[l][r] * c[r][l];
        }
    }
    cout << ans << endl;
    return 0;
}
