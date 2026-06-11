#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    if (n >= b) n = b - 1;
    cout << (a * n) / b + a * (n / b);
    return 0;
}