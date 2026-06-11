#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n, ans = 0;
    cin >> n;
    rep(i, n)
    {
        string s;
        s = to_string(i + 1);
        if (s.size() % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}