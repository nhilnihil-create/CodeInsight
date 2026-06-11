#include <bits/stdc++.h>
using namespace std;

void solve(string s, string t)
{
    map<char, vector<int>> positions;
    for (int i = 0; i < (int)s.size(); i++)
    {
        positions[s.at(i)].push_back(i + 1);
    }

    for (int i = 0; i < (int)t.size(); i++)
    {
        if (positions.count(t.at(i)) == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    int64_t res = 0, p = 0;
    for (int i = 0; i < (int)t.size(); i++)
    {
        auto it = upper_bound(positions.at(t.at(i)).begin(), positions.at(t.at(i)).end(), p);
        if (it == positions.at(t.at(i)).end())
        {
            int p_n = positions.at(t.at(i)).at(0);
            res += (s.size() - p) + p_n;
            p = p_n;
        }
        else
        {
            int p_n = *it;
            res += p_n - p;
            p = p_n;
        }
    }
    cout << res << endl;
}

int main()
{
    string s, t;
    cin >> s >> t;
    solve(move(s), move(t));
    return 0;
}
