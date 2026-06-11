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

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> vvi(n, vector<int>(m));
    vector<int> cost(n);
    REP(i, n)
    {
        cin >> cost[i];
        REP(j, m)
        {
            cin >> vvi[i][j];
        }
    }
    int ans = 1e9;
    REP(i, 1 << n)
    {
        int sum = 0;
        vector<int> rikai(m, 0);
        REP(j, n)
        {
            if (i & (1 << j)) {
                sum += cost[j];
                REP(k, m)
                rikai[k] += vvi[j][k];
            }
        }
        bool f = true;
        REP(j, m)
        {
            if (rikai[j] < x) {
                f = false;
                break;
            }
        }
        if (f) {
            ans = min(ans, sum);
        }
    }
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}