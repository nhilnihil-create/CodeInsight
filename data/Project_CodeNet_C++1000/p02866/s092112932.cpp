#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll N;
    cin >> N;
    vector<ll> D(N);
    REP(i, N) cin >> D[i];
    if (D[0] != 0) {
        PRINT(0);
        return 0;
    }
    map<ll, ll> m;
    REP(i, N) m[D[i]]++;
    ll ans = 1;
    FOR(i, 1, N) {
        ans *= m[D[i]-1];
        ans %= 998244353;
    }
    PRINT(ans);
    return 0;
}
