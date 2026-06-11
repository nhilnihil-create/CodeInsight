#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    int ans = 0;

    while(n != 0) {
        n /= k;
        ++ans;
    }

    printf("%d\n", ans);

    return 0;
}