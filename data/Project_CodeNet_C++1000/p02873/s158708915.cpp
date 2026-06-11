#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int n = s.length() + 1;
    vector<int> a(n);

    for (int i = 0; i <= n - 2; i++)
    {
        if (s[i] == '<')
            a[i + 1] = a[i] + 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '>')
            a[i] = max(a[i + 1] + 1, a[i]);
    }

    ll ans = 0;
    rep(i, n) ans += a[i];
    cout << ans << endl;
}