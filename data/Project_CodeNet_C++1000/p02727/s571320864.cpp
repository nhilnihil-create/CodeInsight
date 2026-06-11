#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<vector<ll>> vvll(3);
    REP(i, a)
    {
        int z;
        cin >> z;
        vvll[0].push_back(z);
    }
    REP(i, b)
    {
        int z;
        cin >> z;
        vvll[1].push_back(z);
    }
    REP(i, c)
    {
        int z;
        cin >> z;
        vvll[2].push_back(z);
    }
    sort(vvll[0].begin(), vvll[0].end());
    sort(vvll[1].begin(), vvll[1].end());
    sort(vvll[2].begin(), vvll[2].end());

    ll ans = 0;
    REP(i, x)
    ans += vvll[0][vvll[0].size() - 1 - i];
    REP(i, y)
    ans += vvll[1][vvll[1].size() - 1 - i];
    int idx[2];
    idx[0] = a - x;
    idx[1] = b - y;
    REP(i, c)
    {
        if (idx[0] >= a && idx[1] >= b)
            break;
        int exidx = -1;
        if (idx[0] >= a)
            exidx = 1;
        if (idx[1] >= b)
            exidx = 0;
        if (exidx == -1) {
            if (vvll[0][idx[0]] < vvll[1][idx[1]])
                exidx = 0;
            else
                exidx = 1;
        }

        if (vvll[exidx][idx[exidx]] < vvll[2][c - 1 - i]) {
            ans += vvll[2][c - 1 - i] - vvll[exidx][idx[exidx]];
            idx[exidx]++;
        } else {
            break;
        }
    }
    cout << ans << endl;
}