# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;

int n;

int main()
{
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i * 1ll * (n - i + 1);
    }
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans -= u * 1ll * (n - v + 1);
    }
    cout << ans << endl;
}
