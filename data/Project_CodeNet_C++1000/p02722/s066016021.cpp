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

void solve() {
    ll n;
    cin >> n;

    /**
     *  K  2......N
     *  
     *  If K|N, replace N/K; no other choice
     *  otherwise, replace N-K
     * 
     * For K == N,
     *      op : 1
     * if K|N, then N/K until cannot divide
     * N%K == 1
     * N == 1 mod K
     * N-1 == 0 mod K
     * K divides N-1 : find divisor of N-1...
     */
    ll ans = 0;
    
    /**
    for (ll i = 2; i <= n; ++i) {
        ll t = n;
        ll k = i;
        while (t%k == 0) {
            t = t/k;
        }
        t = t%k;
        if (t==1) {
            ans++;
        }
    }
    */
   for (ll i = 1; i*i <= n; ++i) {
       ll k = i;
       if (n%k == 0) {
           ll _n = n;
           //k is a divisor
           while (k != 1 && _n%k==0) {
               _n = _n/k;
           }
           _n = _n%k;
           if (k != 1 && _n == 1) {
               ++ans;
           }

           if (n != k*k) {
                //n/k is a divisor
                k = n/k;
                _n = n;
                while (k != 1 && _n%k==0) {
                    _n = _n/k;
                }
                _n = _n%k;
                if (k != 1 && _n == 1) {
                    ++ans;
                }
           }
       }
   }

   for (ll i = 1; i*i <= n-1; ++i) {
       ll k = i;
       if ((n-1)%k == 0) {
           if (k != 1) {
               ++ans;
           }
           if ((n-1) != k*k) {
               k = (n-1) / k;
               if (k != 1) {
                   ++ans;
               }
           }
       }
   }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef D_LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif

    solve();

    return 0;
}