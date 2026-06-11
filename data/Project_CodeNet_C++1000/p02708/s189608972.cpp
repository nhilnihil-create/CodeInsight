#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll n, K;
    cin >> n >> K;

    ll res = 0;
    ll MOD = 1000000007;
    for (ll i = K; i <= n + 1; i++) {
        // min: 0 + 1 + 2 + ... + K-1
        // max: n + n-1 + ... + n-k+1
        ll mi = i * (i - 1) / 2;
        ll ma = n * (n + 1) / 2 - (n - i) * (n - i + 1) / 2;
        res += (ma - mi + 1) % MOD;
        res %= MOD;
    }

    put(res);
}
signed main(){ Main();return 0;}