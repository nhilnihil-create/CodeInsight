#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

ll n, cnt[300009] = {}, cnt2[300009] = {}, mx[300009] = {};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    rep(i, n + 1) cnt2[cnt[i]]++;
    FOR(i, 1, n + 1) mx[i] = mx[i - 1] + i * cnt2[i];
    ll sum = 0;
    for(int i = n - 1; i > 0; i--)
        (mx[i] += i * (sum += cnt2[i + 1])) /= i;
    mx[n] /= n;
    mx[0] = 1e18;

    int x = n;
    FOR(i, 1, n + 1) {
        while(mx[x] < i)
            x--;
        cout << x << endl;
    }
}