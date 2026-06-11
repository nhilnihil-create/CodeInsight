#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n, p;
char s[200005];
ll dp[200005], bin[10005];

ll mod_power(ll x, ll n, ll M) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return mod_power((x * x) % M, n / 2, M);
    } else {
        return (mod_power((x * x) % M, n / 2, M) * x) % M;
    }
}

int main() {
    cin >> n >> p;
    cin >> s;
    if (p != 2 && p != 5) {
        bin[0] = 1;
        rrep(i, n) {
            dp[i] = (dp[i + 1] + mod_power(10, n - i - 1, p) * (s[i] - '0')) % p;
            bin[dp[i]]++;
        }
        ll ans = 0;
        rep(i, p) { ans += bin[i] * (bin[i] - 1) / 2; }
        cout << ans << endl;
    } else {
        ll ans = 0;
        rep(i, n) {
            if ((s[i] - '0') % p == 0) {
                ans += i + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}