#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (a > k) {
        a -= k;
    } else if (a + b > k) {
        b -= (k - a);
        a = 0;
    } else {
        a = 0;
        b = 0;
    }
    cout << a << " " << b << endl;
    return 0;
}