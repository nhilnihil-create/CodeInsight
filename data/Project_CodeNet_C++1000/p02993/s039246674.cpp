#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool ok = true;

    for (int i = 1; i < 4; ++i)
        if (s[i] == s[i - 1])
        {
            ok = false;
            break;
        }

    cout << (ok ? "Good" : "Bad") << '\n';

    return 0;
}
