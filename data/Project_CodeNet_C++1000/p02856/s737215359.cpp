#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int m;
    cin >> m;
    vector<ll> d(m);
    vector<ll> c(m);
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> d[i] >> c[i];
        ans += c[i];
        sum += d[i] * c[i];
    }
    cout << ans - 1 + (sum-1) / 9 << endl;
}
