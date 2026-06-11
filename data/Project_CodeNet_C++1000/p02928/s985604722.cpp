#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> B(N*2);
    REP(i, N) {
        B[i] = A[i];
        B[N+i] = A[i];
    }
    ll cnt1 = 0;
    REP(i, N) {
        FOR(j, i+1, N) {
            if (A[i] > A[j]) cnt1++;
        }
    }
    ll cnt2 = 0;
    REP(i, N*2) {
        FOR(j, i+1, N*2) {
            if (B[i] > B[j]) cnt2++;
        }
    }
    ll t = cnt2 - cnt1 * 2;

    ll ans = cnt1 * K;
    ans %= MOD;
    ll tmp = (K-1)*K;
    tmp /= 2;
    tmp %= MOD;
    tmp *= t;
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
    PRINT(ans);
    return 0;
}
