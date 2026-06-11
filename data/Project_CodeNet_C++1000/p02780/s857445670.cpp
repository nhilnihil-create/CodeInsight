#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]++;
    }

    vector<ll> s(n + 1, 0);
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

    ll res = 0;
    for (int i = 0; i <= n - k; i++) res = max(res, s[i + k] - s[i]);

    cout << fixed << setprecision(12) << (double)res / 2 << endl;
    return 0;
}
