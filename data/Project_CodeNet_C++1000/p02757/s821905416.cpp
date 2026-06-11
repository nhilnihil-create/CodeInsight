#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 200005;
const int MOD = 10005;

int ten[N], t[N], cnt[MOD];

int main() {

    FAST;

    int n, p;
    cin >> n >> p;
    string a;
    cin >> a;
    a = " " + a;
    if (p == 2 || p == 5) {
        intt ans = 0;
        for (int i = 1; i <= n; i ++) {
            if ((int(a[i]) - '0') % p == 0) {
                ans += i;
            }
        }
        cout << ans << '\n';
    }
    else {
        ten[0] = 1;
        for (int i = 1; i <= n; i ++) {
            ten[i] = (ten[i - 1] * 10) % p;
        }
        t[n] = 0;
        for (int i = n - 1; i >= 0; i --) {
            t[i] = (t[i + 1] + ten[n - i - 1] * (int(a[i + 1]) - '0')) % p;
        }
        for (int i = 0; i <= n; i ++) {
            cnt[t[i]] ++;
        }
        intt ans = 0;
        for (int i = 0; i < p; i ++) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
