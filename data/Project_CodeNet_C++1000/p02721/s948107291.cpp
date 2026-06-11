#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int32_t main() {
    fast_io();
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int i = n, num = 0;
    vector <int> l, r;
    while (i >= 1)
    {
        if (s[i - 1] == 'o')
        {
            num++;
            r.pb(i);
            i -= c;
        }
        i--;
    }
    if (num != k)
        return 0;
    i = 1;
    reverse(r.begin(), r.end());
    while (i <= n)
    {
        if (s[i - 1] == 'o')
        {
            l.pb(i);
            i += c;
        }
        i++;
    }
    for (int i = 0; i < (int)l.size(); i++)
    {
        if (l[i] == r[i])
            cout << l[i] << " ";
    }
    return 0;
}