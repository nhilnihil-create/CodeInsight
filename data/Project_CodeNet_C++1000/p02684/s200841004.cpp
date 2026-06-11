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
    int n;
    ll x;
    cin >> n >> x;
    vector<int> to(n);
    REP(i, n)
    {
        cin >> to[i];
        to[i]--;
    }
    vector<vector<int>> root(n, vector<int>(64)); //[from][2^i]
    REP(i, 64)
    {
        REP(j, n)
        {
            if (i == 0) {
                root[j][i] = to[j];
            } else {
                root[j][i] = root[root[j][i - 1]][i - 1];
            }
        }
    }
    int ans = 0;
    REP(i, 64)
    {
        if (x & (1LL << i)) {
            ans = root[ans][i];
        }
    }
    cout << ans + 1 << endl;
}