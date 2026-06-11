#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int X;
    cin >> X;

    set<ll> s{0};

    ll i5_prev = 0;
    for (ll i = 1; ; ++i) {
        ll i5 = i * i * i * i * i;
        if (i5 - i5_prev > X) {
            break;
        }
        s.insert(i5);
        i5_prev = i5;
    }

    for (ll A = 0; ; ++A) {
        ll A5 = A * A * A * A * A;
        ll abs_B5 = abs(A5 - X);
        if (s.count(abs_B5)) {
            for (ll abs_B = 0; ; ++abs_B) {
                if (abs_B * abs_B * abs_B * abs_B * abs_B == abs_B5) {
                    ll B;
                    if (A5 - X >= 0) {
                        B = abs_B;
                    } else {
                        B = -abs_B;
                    }
                    cout << A << " " << B << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
