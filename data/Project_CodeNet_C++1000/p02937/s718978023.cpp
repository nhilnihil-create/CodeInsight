#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string s, t;
    map<char, vi> mp;
    cin >> s >> t;
    REP(i, s.size())
    {
        mp[s.at(i)].emplace_back(i + 1);
        mp[s.at(i)].emplace_back((i + 1) + s.size());
    }
    REP(i, t.size())
    {
        if (!mp.count(t[i]))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        sort(ALL(i->second));
    }
    int ans = 0;
    int tmp = 0;
    REP(i, t.size())
    {
        char c = t[i];
        auto left = lower_bound(mp[c].begin(), mp[c].end(), tmp + 1);
        ans += (*left - tmp);
        tmp = *left;
        tmp %= s.size();
    }
    cout << ans << endl;

    return 0;
}