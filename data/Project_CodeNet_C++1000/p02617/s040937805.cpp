#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int n;
long long ans;
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    cin >> n;
    for (int len = 1; len <= n; len++)
    {
        ans += 1LL * len * (n - len + 1);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        ans -= 1LL * u * (n - v + 1);
    }
    cout << ans;
    return 0;
}