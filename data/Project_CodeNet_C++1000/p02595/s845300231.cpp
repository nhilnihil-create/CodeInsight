#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void run() {
    ll n, d;
    cin >> n >> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >>x >> y;
        if (x * x + y * y <= d * d) ++ans;
    }
    cout <<ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    run();
    return 0;
}
