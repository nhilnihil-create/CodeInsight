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
    int n, p;
    string s;
    cin >> n >> p >> s;
    if (p == 2 || p == 5) {
        ll ans = 0;
        REP(i, n)
        {
            if ((s[i] - '0') % p == 0) {
                ans += (i + 1);
            }
        }
        cout << ans << endl;
        return 0;
    }
    vector<ll> amari(p, 0);
    amari[0] = 1;
    ll a = 0;
    ll ten = 1;
    REP(i, n)
    {
        a += (s[n - 1 - i] - '0') * ten;
        a %= p;
        amari[a]++;
        ten = (ten * 10) % p;
    }
    ll ans = 0;
    REP(i, p)
    {
        ans += amari[i] * (amari[i] - 1) / 2;
    }
    cout << ans << endl;
}