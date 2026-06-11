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
    vector<ll> vll(1000);
    for (ll i = 0; i < 1000; i++) {
        vll[i] = i * i * i * i * i;
    }
    ll x;
    cin >> x;
    REP(i, 2)
    REP(j, 2)
    REP(k, 1000)
    REP(l, 1000)
    {
        ll a = vll[k];
        ll b = vll[l];
        if (i == 1)
            a *= -1;
        if (j == 1)
            b *= -1;
        if (a - b == x) {
            if (i == 0)
                cout << k;
            else
                cout << -k;

            cout << ' ';
            if (j == 0)
                cout << l;
            else
                cout << -l;

            cout << endl;
            return 0;
        }
    }
}