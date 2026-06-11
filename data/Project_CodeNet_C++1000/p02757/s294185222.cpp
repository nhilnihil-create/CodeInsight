#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

ll N, P;
string S;

ll pow_mod(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    else if (k % 2 == 1) {
        return pow_mod(n, k-1, mod) * n % mod;
    }
    else {
        ll tmp = pow_mod(n, k/2, mod);
        return tmp * tmp % mod;
    }
}

int main() {
    cin >> N >> P >> S;

    if (P == 2 || P == 5) {
        ll ans = 0;
        for (int i = N-1; i >= 0; i--) {
            if ((S[i] - '0') % P == 0) {
                ans += (i+1);
            }
        }
        cout << ans << endl;
    }
    else {
        ll dp[N+1];
        dp[0] = 0;
        dp[1] = (S[N-1] - '0') % P;
        for (ll i = 2; i <= N; i++) {
            dp[i] = (dp[i-1] + pow_mod(10, i-1, P) * (S[N-i] - '0') % P) % P;
        }

        map<ll, ll> mp;
        for (int i = 0; i <= N; i++) {
            mp[dp[i]]++;
        }

        ll ans = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            ll val = itr->second;
            ans += val * (val-1) / 2;
        }

        cout << ans << endl;
    }
    
    return 0;
}
