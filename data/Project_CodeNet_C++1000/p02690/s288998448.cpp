#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int x;
    cin >> x;

    for (int a = 1; a <= 1000; a++) {
        ll i = pow(a, 5);
        for (int b = -1000; b <= 1000; b++) {
            ll j = pow(b, 5);
            if (i - j == x) {
                printf("%d %d\n", a, b);
                return 0;
            }
        }
    }
    return 0;
}