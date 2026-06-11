#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    double a, b, n;
    cin >> a >> b >> n;
    double x = min(n, b - 1);
    ll ans = floor((a * x) / b) - a * floor(x / b);
    cout << ans << endl;
}
