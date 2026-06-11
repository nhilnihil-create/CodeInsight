#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll h;
    cin >> h;
    int cnt = 0;
    while (h > 0) {
        cnt++;
        h /= 2;
    }
    ll ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= 2;
    }
    cout << --ans << endl;
    return 0;
}