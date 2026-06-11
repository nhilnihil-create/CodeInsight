#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    rep(i, n - 1)
    {
        if (s[i] != s[i + 1])
            ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}