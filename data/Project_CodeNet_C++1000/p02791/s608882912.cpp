#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    int mn = 1e9 , ans = 0;
    for (int i = 0 ;i < n ;i++) {
        int x;
        cin >> x;
        ans += x < mn;
        mn = min(mn , x);
    }

    cout << ans;
}