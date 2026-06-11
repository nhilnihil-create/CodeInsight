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

int hat[100010][3];

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint res = 1;

    rep(i, 100000) rep(j, 3) hat[i][j] = 0;

    rep(i, n) {
        int cnt = 0;
        rep(j, 3) if (hat[i][j] == a[i]) cnt++;
        res *= cnt;
        rep(j, 3) {
            if (hat[i][j] == a[i]) {
                hat[i][j]++;
                break;
            }
        }
        rep(j, 3) hat[i+1][j] = hat[i][j];
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}