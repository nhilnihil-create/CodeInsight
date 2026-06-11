#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    string ans;
    cin >> n >> m;
    rep(i, n) ans += '0';
    rep(i, m)
    {
        int s, c;
        cin >> s >> c;
        if (n > 1 && s - 1 == 0 && c == 0)
        {
            cout << "-1" << endl;
            return 0;
        }

        if (ans[s - 1] == '0')
        {
            ans[s - 1] = '0' + c;
        }
        else if (ans[s - 1] != '0' + c)
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    if (n > 1 && ans[0] == '0')
        ans[0] = '1';

    cout << ans << endl;

    return 0;
}