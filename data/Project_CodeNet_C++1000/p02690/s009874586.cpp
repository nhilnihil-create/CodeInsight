#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int f(int x) {
    int r = 1;
    rep(i, 5) {
        r *= x;
    }
    return r;
}

int main() {
    int x;
    cin >> x;
    for (int a = -120; a <= 120; a++) {
        for (int b = -120; b <= 120; b++) {
            if (f(a) - f(b) == x) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}