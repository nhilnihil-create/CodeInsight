#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

ll GCD(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    ll prevcnt = 0;
    rep(i, N) {
        cin >> a[i];
        ll copy = a[i];
        ll cnt = 0;
        while (copy % 2 == 0) {
            copy /= 2;
            cnt++;
        }
        if (i != 0 && prevcnt != cnt) {
            cout << 0 << endl;
            return 0;
        }
        prevcnt = cnt;
    }

    ll lcm = a[0] / 2;
    rep(i, N) { lcm = LCM(lcm, a[i] / 2); }

    ll cnt = (M / lcm + 1) / 2;
    cout << cnt << endl;
}