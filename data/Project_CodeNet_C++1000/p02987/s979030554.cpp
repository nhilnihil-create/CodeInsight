#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, s.size()) mp[s[i]]++;
    bool ok = true;
    for (auto p : mp)
    {
        if (p.second != 2)
            ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}