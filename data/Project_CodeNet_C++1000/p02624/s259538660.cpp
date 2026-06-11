#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    long long ans = 0;
    for (int div = 1 ; div <= n ; div++)
        for (int mul = div ; mul <= n ; mul += div)
            ans += mul;

    cout << ans;
}