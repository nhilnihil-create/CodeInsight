#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin() , a.end());

    int rem = max(0 , n - k);

    long long ans = 0;
    for (int i = 0; i < rem ;i++)
        ans += a[i];

    cout << ans;
}