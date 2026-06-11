#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int k;
    cin >> k;
    int sum = 0;
    int a[n];
    rep(i, n) cin >> a[i], sum += a[i];
    int ans = 0;
    for(int i = 1; i * i <= sum; i++) {
        if(sum % i) continue;
        {
            int x = 0;
            int b[n];
            rep(j, n) b[j] = a[j] % i, x += b[j];
            sort(b, b + n);
            x /= i;
            int s = 0;
            rep(j, n - x) s += b[j];
            if(s <= k) chmax(ans, i);
        }
        {
            int I = sum / i;
            int x = 0;
            int b[n];
            rep(j, n) b[j] = a[j] % I, x += b[j];
            sort(b, b + n);
            x /= I;
            int s = 0;
            rep(j, n - x) s += b[j];
            if(s <= k) chmax(ans, I);
        }
    }

    cout << ans << endl;

    return 0;
}