#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

void solve()
{
    string s, t;
    cin >> s >> t;
    map<char, vector<int>> char_indices;
    REP0 (i, s.length())
    {
        char_indices[s[i]].push_back(i);
    }

    LL cnt = 0;
    int i_in_period = -1;
    int s_N = s.length();
    for (auto c : t)
    {
        if (char_indices.find(c) == char_indices.end())
        {
            std::cout << -1 << endl;
            return;
        }

        // 最も近い次の文字の出てくる添字を探す
        int ng = -1;
        int ok = char_indices[c].size();
        int mid = 0;
        while (abs(ok - ng) > 1)
        {
            mid = (ok + ng) / 2;
            if (i_in_period < char_indices[c][mid])
                ok = mid;
            else
                ng = mid;
        }

        if (ok == int(char_indices[c].size()))
        {
            cnt += s_N;
            i_in_period = char_indices[c][0];
        }
        else
        {
            i_in_period = char_indices[c][ok];
        }
    }
    cnt += i_in_period + 1;
    std::cout << cnt << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
