#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.rbegin() , a.rend());

    long long ans = a.front();
    for (int i = 1 , j = 2 ;j < n ;j += 2 , i++) {
        if (j + 1 < n)
            ans += 2 * a[i];
        else
            ans += a[i];
    }

    cout << ans;
}