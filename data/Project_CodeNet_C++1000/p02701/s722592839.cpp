#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    rep (i, n)
        cin >> s[i];

    int ans = 1;
    sort(s.begin(), s.end());
    rep (i, n - 1)
        if (s[i] == s[i + 1])
            continue;
        else
            ans++;

    cout << ans << endl;
    return 0;
}