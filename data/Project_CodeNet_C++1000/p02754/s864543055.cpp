#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ab = a + b;
    ll r;
    if (n % ab < a) {
        r = n % ab;
    } else {
        r = a;
    }
    cout << (n / ab) * a + r << endl;
    return 0;
}