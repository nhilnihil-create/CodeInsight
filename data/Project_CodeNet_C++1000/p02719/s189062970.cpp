#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll n, k;
    cin >> n >> k;
    n %= k;
    if (k - n > n) {
        cout << n << endl;
    } else {
        cout << k - n << endl;
    }
    return 0;
}