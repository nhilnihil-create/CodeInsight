#include <iostream>

using namespace std;

const int Z = 1e9+7;

int bexp(int a, int x) {
    if (x == 0) {
        return 1;
    }
    if (x % 2 == 1) {
        return 1ll * a * bexp(a, x - 1) % Z;
    }
    int t = bexp(a, x / 2);
    return 1ll * t * t % Z;
}

int inv(int a) {
    return bexp(a, Z - 2);
}

int c(int n, int x) {
    int r = 1;
    for (int i = 1; i <= x; i++) {
        r = 1ll * r * (n + 1 - i) % Z * inv(i) % Z;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    cout << (0ll + 2 * Z + bexp(2, n) - 1 - c(n, a) - c(n, b)) % Z << endl;

    return 0;
}
