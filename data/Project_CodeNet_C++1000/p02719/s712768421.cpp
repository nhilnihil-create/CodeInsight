#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k; // 変数

int main() {
// input
    cin >> n;
    cin >> k;
// solve
    ll ans = 0;
    if (n > k) n %= k;
    ans = min(n, abs(n-k));
// output
    cout << ans << "\n";
}