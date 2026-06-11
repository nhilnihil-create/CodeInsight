#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) ans++;
    cout << ans << '\n';
    return 0;
}
