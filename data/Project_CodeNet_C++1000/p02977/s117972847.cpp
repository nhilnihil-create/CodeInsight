#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

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

    int N;
    cin >> N;

    if(__builtin_popcount(N) == 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    int n = N;
    if(n % 2 == 0) n--;

    FOR(i, 2, n + 1) cout << 1 << " " << i << endl;
    FOR(i, 2, n + 1) cout << i << " " << (i ^ 1) + N << endl;
    cout << 2 + N << " " << 1 + N << endl;
    if(N != n) {
        cout << N << " " << N - 1 << endl;
        cout << 2 * N << " " << (N ^ 1 ^ N - 1) << endl;
    }

    return 0;
}