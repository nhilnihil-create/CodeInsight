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

ll powmod(ll n, ll x)
{
    vector<ll> vll(32);
    vll[0] = n;
    FOR(i, 1, 32)
    {
        vll[i] = (vll[i - 1] * vll[i - 1]) % MOD;
    }
    ll ret = 1;
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            ret = (ret * vll[cnt]) % MOD;
        }
        x >>= 1;
        cnt++;
    }
    return ret;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    /*
    vector<ll> prime(k + 1, 0);
    FOR(i, 2, k + 1)
    {
        for (int j = i; j < k + 1; j += i) {
            if (prime[j] == 0) {
                prime[j] =i;
            }
        }
    }*/
    ll ans = 0;
    vector<ll> numgcd(k + 1);
    for (int i = k; i >= 1; i--) {
        numgcd[i] = powmod(k / i, n);
        for (int j = i * 2; j <= k; j += i) {
            numgcd[i] -= numgcd[j];
            numgcd[i] = (numgcd[i] + MOD) % MOD;
        }
        ll add = (numgcd[i] * i) % MOD;
        ans = (ans + add) % MOD;
    }
    cout << ans << endl;
}