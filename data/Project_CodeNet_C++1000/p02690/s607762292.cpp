#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll X;
    cin >> X;
    for (ll A = -300; A < 300; A++) {
        for (ll B = -300; B < 300; B++) {
            ll A5 = A * A * A * A * A;
            ll B5 = B * B * B * B * B;
            if (A5 - B5 == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
    return 0;
}
