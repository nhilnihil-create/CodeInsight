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


    auto sum = [&] (int n) {
        return n * (n + 1) / 2;
    };

    double exp = 0;
    for (int i = 0 ;i < k ;i++)
        exp += sum(a[i]) / double(a[i]);

    double mx = exp;
    for (int i = k ;i < n ;i++) {
        exp += sum(a[i]) / double(a[i]);
        exp -= sum(a[i - k]) / double(a[i - k]);
        mx = max(mx , exp);
    }

    cout << fixed << setprecision(12) << mx;
}
