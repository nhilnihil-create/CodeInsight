#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#define int long long

void solve()
{
    string s;
    cin >> s;
    if(s[s.size() - 1] == 's')
        s += "es";
    else
        s += "s";
    cout << s << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}