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
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint s = accumulate(all(a), 0LL);

    lint s_odd = 0, s_even = 0;
    rep(i, (n+1)/2) {
        s_even += 2 * a[(2 * i) % n];
        s_odd += 2 * a[(1 + 2 * i) % n];
    }

    vec b(n);

    rep(i, n) {
        lint s2 = 0;

        if (i >= 2) {
            if (i % 2 == 0) {
                s_even -= 2 * a[i-2];
                s_even += 2 * a[i-1];
            }
            else {
                s_odd -= 2 * a[i-2];
                s_odd += 2 * a[i-1];
            }
        }

        if (i % 2 == 0) s2 = s_even;
        else s2 = s_odd;

        s2 -= s;
        b[i] = s2;
    }

    rep(i, n) {
        if (i != 0) cout << " ";
        cout << b[i];
    }    
    cout << endl;
    return 0;
}