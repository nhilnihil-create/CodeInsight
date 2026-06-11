#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 500 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f, BSZ = 320;
int N, K;
int a[MN];

bool f(ll x) {
    vector<ll> rem;
    for (int i = 1; i <= N; i++) {
        int r = a[i] % x;
        if (r != 0) rem.push_back(r);
    }
    if (rem.empty()) return true;
    sort(all(rem));
    ll cnt = 0;
    int l = 0, r = rem.size() - 1;
    while (l < r) {
        ll add = min(rem[l], x - rem[r]);
        rem[l] -= add;
        rem[r] += add;
        cnt += add;
        if (rem[l] == 0) l++;
        else r--;
    }
    if (rem[l] % x) return false;
    return cnt <= K;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    ll sum = 0, mx = 0;
    for (int i = 1; i <= N; i++) cin >> a[i], sum += a[i];
    for (ll i = 1; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            if (f(sum / i)) mx = max(mx, sum / i);
            if (f(i)) mx = max(mx, i);
        }
    }
    cout << mx << '\n';
    return 0;
}
