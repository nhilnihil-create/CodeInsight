#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    string s;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        m[s]++;
        mx = max(mx, m[s]);
    }
    cerr << mx << endl;
    for (auto &&p : m)
    {
        if (mx == p.second)
            cout << p.first << endl;
    }

    return 0;
}