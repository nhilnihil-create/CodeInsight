#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    ll N, D, c = 0;
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if (x * x + y * y <= D * D) {
            c++;
        }
    }
    cout << c << endl;
}