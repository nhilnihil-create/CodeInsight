#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int mcnt = 0;
    for (auto cnt : mp)
    {
        mcnt = max(mcnt, cnt.second);
    }
    for (auto ans : mp)
    {
        if (mcnt == ans.second)
            cout << ans.first << endl;
    }
    return 0;
}