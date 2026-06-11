#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
constexpr ll M = 1e9 + 7;
inline ll sum_1(const ll n) { return ((n * (n + 1)) / 2) % M; }
inline ll sum_2(const ll n) { return ((n * (n + 1) * (2 * n + 1)) / 6) % M; }
inline ll sum_3(const ll n) { return (((n * (n + 1)) / 2) % M * ((n * (n + 1)) / 2) % M) % M; }
inline ll sum_1(const ll i, const ll j) { return (sum_1(j) - sum_1(i - 1) + M) % M; }
inline ll sum_2(const ll i, const ll j) { return (sum_2(j) - sum_2(i - 1) + M) % M; }
inline ll sum_3(const ll i, const ll j) { return (sum_3(j) - sum_3(i - 1) + M) % M; }

ll pow_f(ll base, ll exp) {
    ll ans = 1;
    base = base % M;
    while (exp) {
        if (exp&1) {
            ans = (ans * base) % M;
        }
        base = (base * base) % M;
        exp >>= 1;
    }
    return ans;
}


void solve() {
    ll n, k;
    cin >> n >> k;
    /**
     * GCD can lie between 1....K
     * Count no. of sequence having gcd X \in 1...K
     * 
     * gcd X i.e all are divisible by X atleast K/X**N
     * 
     */
    ll ans = 0;
    vector<ll> cntSeq(k+1, 0);
    for (int i = k; i >= 1; --i) {
        ll temp = pow_f((k/i), n);
        ll multiplier = 2;
        while (multiplier*i <= k) {
            temp = (temp - cntSeq[multiplier*i] + M)%M;
            ++multiplier;
        }
        cntSeq[i] = temp;
        ans = (ans + (i*temp)%M)%M;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif

    solve();

    return 0;
}