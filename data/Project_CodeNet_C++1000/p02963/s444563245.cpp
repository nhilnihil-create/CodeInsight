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
    ll S;
    cin >> S;
    ll tmp = 1000000000;
    ll n = S / tmp;
    ll m = S % tmp;
    if (n == tmp) {
        PRINT(0 << " " << 0 << " " << tmp << " " << 0 << " " << 0 << " " << tmp);
    } else {
        PRINT(0 << " " << 0 << " " << 1 << " " << tmp << " " << n+1 << " " << tmp - m);
    }

    return 0;
}
