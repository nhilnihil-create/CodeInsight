#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> testimony(n, vector<pair<int, int>>());
    int x, y;
    rep(i, n)
    {
        cin >> a[i];
        rep(j, a[i])
        {
            cin >> x >> y;
            x--;
            testimony[i].push_back({x, y});
        }
    }
    int cnt_max = 0;
    bool honesty;
    bool hone_check;
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        bool check_ok = true;
        rep(i, n)
        {
            if (bit & (1 << i))
                honesty = true;
            else
                honesty = false;
            rep(j, testimony[i].size())
            {
                hone_check = bit & (1 << testimony[i][j].first);
                if (honesty)
                {
                    if (hone_check != bool(testimony[i][j].second))
                        check_ok = false;
                }
            }
        }
        if (check_ok)
            cnt_max = MAX(cnt_max, __builtin_popcount(bit));
    }
    cout << cnt_max << endl;
    return 0;
}