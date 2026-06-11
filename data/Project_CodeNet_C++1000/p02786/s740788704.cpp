#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    ll h;
    cin >> h;
    ll cnt = 0;
    ll r = 1;
    while (h > 0) {
        h /= 2;
        cnt += r;
        r *= 2;
    }
    cout << cnt << endl;
}