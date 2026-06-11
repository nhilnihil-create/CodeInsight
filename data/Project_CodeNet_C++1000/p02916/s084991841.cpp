#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll MINF = LLONG_MIN;
const int INT_INF = INT_MAX;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> c[i];
        c[i];
    }
    int mae = -100;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += b[a[i]] + (a[i] == mae + 1 ? c[mae] : 0);
        mae = a[i];
    }
    cout << ans << endl;
}