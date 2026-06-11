#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    bool ok = true;
    string t = s;
    reverse(t.begin(), t.end());
    if (s != t)
        ok = false;

    int n = s.size();
    t = s.substr(0, (n - 1) / 2);
    string r = t;
    reverse(r.begin(), r.end());
    if (t != r)
        ok = false;

    t = s.substr((n + 3) / 2 - 1);
    r = t;
    reverse(r.begin(), r.end());
    if (t != r)
        ok = false;

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}