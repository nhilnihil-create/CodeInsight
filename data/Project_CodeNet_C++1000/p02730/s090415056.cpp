#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    bool ok = true;
    rep (i, n / 2)
        if (s[i] != s[n - 1 - i])
            ok = false;
    rep (i, (n - 1) / 2 / 2)
        if (s[i] != s[(n - 1) / 2 - 1 - i])
            ok = false;
    for (int i = (n + 3) / 2 - 1, cnt = 0; i < n; i++, cnt++)
        if (s[i] != s[n - 1 - cnt])
            ok = false;

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}