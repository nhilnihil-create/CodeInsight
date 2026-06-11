#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    string a, b;
    cin >> a >> b;
    int ans = 1e9;
    int n = a.size();
    int m = b.size();
    for (int i = 0; i < n - m + 1; i++)
    {
        int cnt = 0;
        int j = 0;
        int x = i;
        for (int k = 1; k <= m; k++)
        {
            cnt += (a[x] != b[j]);
            x++;
            j++;
        }

        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}