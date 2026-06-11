#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
        i %= k;
    }
    vector<ll> sum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] + a[i]) % k;
    }
    map<ll, vector<ll>> cnt;
    for(int i = 0; i <= n; i++) {
        ll diff = ((i - sum[i]) % k + k) % k;
        cnt[diff].push_back(i);
    }
    ll ans = 0;
    for(auto p : cnt) {
        auto v = p.second;
        ll tmp = (ll)v.size() * ((ll)v.size() - 1) / 2;
        for(auto i : v) {
            auto it = lower_bound(ALL(v), i + k);
            tmp -= v.end() - it;
        }
        ans += tmp;
    }
    cout << ans << endl;
}