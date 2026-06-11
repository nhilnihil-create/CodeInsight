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

    int n, m;
    string s;
    cin >> n >> m >> s;
    V<int> ans;
    for(int i = n, j; i > 0; i -= j) {
        for(j = min(m, i); s[i - j] == '1';)
            j--;
        if(j == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(j);
    }
    reverse(ALL(ans));
    for(int x : ans)
        cout << x << endl;

    return 0;
}