#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, a, b, ans;
    cin >> n >> a >> b;

    if ((b - a) % 2 == 0) ans = (b - a) / 2;
    else {
        if (a > n - b + 1) {
            ans = (b - a - 1) / 2 + (n - b + 1);
        } else {
            ans = (b - a - 1) / 2 + a;
        }
    }
    cout << ans << endl;
    return 0;
}