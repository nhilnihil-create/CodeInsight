#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define in insert

#define pii pair<int, int>
#define ll long long
#define lb long double

#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define m_p(i, j) make_pair(i, j)
#define mem(a, x) memset(a, x, sizeof(a))
#define endl "\n"
#define all(x) x.begin(), x.end()

string s, t;
int solve()
{
    int ma = 0;
    for (int st = 0; st + t.size() <= s.size(); st++) {
        int ed = st + t.size(), cnt = 0;
        for (int i = st; i < ed; i++) {
            int id = i - st;
            if (t[id] == s[i])
                cnt++;
        }
        ma = max(cnt, ma);
    }
    return t.size() - ma;
}
int main()
{
    cin >> s >> t;
    cout << solve() << endl;

    return 0;
}
