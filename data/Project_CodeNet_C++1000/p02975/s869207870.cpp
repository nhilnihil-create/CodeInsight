#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // all zero
    bool allzero = true;
    rep(i, n) {
        if (a[i] != 0) allzero = false;
    }
    if (allzero) {
        cout << "Yes\n";
        return 0;
    }

    if (n % 3 != 0) {
        cout << "No\n";
        return 0;
    }

    sort(a.begin(), a.end(), greater<ll>());

    bool allsame = true, allzero2 = true;

    rep(i, 2 * n / 3 - 1) {
        if (a[i] != a[i + 1]) allsame = false;
    }
    for (ll i = 2 * n / 3; i < n; i++) {
        if (a[i] != 0) allzero2 = false;
    }

    if (allsame && allzero2) {
        cout << "Yes\n";
        return 0;
    }

    vector<ll> num, ins_cnt;
    a.push_back(-1ll);
    ll cnt = 1;

    rep(i, a.size() - 1) {
        if (a[i] == a[i + 1]) {
            cnt++;
        } else {
            ins_cnt.push_back(cnt);
            num.push_back(a[i]);
            cnt = 1;
        }
    }

    // rep(i, num.size()) { cout << num[i] << "\n"; }

    if (num.size() != 3) {
        cout << "No\n";
        return 0;
    }

    if (!(ins_cnt[0] == ins_cnt[1] && ins_cnt[1] == ins_cnt[2])) {
        cout << "No\n";
        return 0;
    }

    if (!(num[0] == (num[1] ^ num[2]) && num[1] == (num[0] ^ num[2]) &&
          num[2] == (num[0] ^ num[1]))) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}