#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    ll b, n;
    cin >> a >> b >> n;

    printf("%lld\n", min(a * (b - 1) / b, a * n / b));

    return 0;
}