#include <bits/stdc++.h>

using namespace std;

long long solve (long long h) {
    if (h == 1)
        return 1;
    return 1 + solve(h / 2) * 2;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    long long h;
    cin >> h;
    cout << solve(h);
}
