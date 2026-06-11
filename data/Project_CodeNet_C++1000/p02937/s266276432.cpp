#include <bits/stdc++.h>
using namespace std;

void solve(string s, string t)
{
    int sn = s.size(), tn = t.size();
    vector<vector<int>> positions(26);
    for (int i = 0; i < sn; i++)
    {
        positions.at(s.at(i) - 'a').push_back(i);
    }
    for (int i = 0; i < sn; i++)
    {
        positions.at(s.at(i) - 'a').push_back(sn + i);
    }

    for (int i = 0; i < tn; i++)
    {
        if (positions.at(t.at(i) - 'a').size() == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    int64_t res = 0, p = 0;
    for (int i = 0; i < tn; i++)
    {
        int p_n = *lower_bound(positions.at(t.at(i) - 'a').begin(), positions.at(t.at(i) - 'a').end(), p) + 1;
        if (p_n >= sn)
        {
            res += sn;
            p_n -= sn;
        }
        p = p_n;
    }
    res += p;
    cout << res << endl;
}

int main()
{
    string s, t;
    cin >> s >> t;
    solve(move(s), move(t));
    return 0;
}
