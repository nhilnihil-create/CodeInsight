#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const lint INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint l = 0;
    lint r = accumulate(all(a), 0LL);
    lint mi = INF;

    rep(i, n-1) {
        l += a[i];
        r -= a[i];
        mi = min(mi, abs(l-r));
    }

    cout << mi << endl;
    return 0;
}