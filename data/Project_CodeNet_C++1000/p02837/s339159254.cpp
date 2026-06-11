#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (s); i < (long long)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);
const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vvll a(N), b(N);
    rep(i, N) {
        ll j;
        cin >> j;
        rep(k, j) {
            ll x, y;
            cin >> x >> y;
            if (y) a[i].push_back(x - 1);
            else b[i].push_back(x - 1);
        }
    }
    ll ans = 0;
    for (ll bit = 0; bit < (1 << N); bit++) { 
        vll c(N, 0), d(N, -1);
        bool flag = true;
        rep(i, N) {
            if (bit & (1 << i)) {
                c[i] = 1;
                for (auto x : a[i]) {
                    if (d[x] == 0) flag = false;
                    else d[x] = 1;
                }
                 for (auto x : b[i]) {
                     if (d[x] == 1) flag = false;
                     else d[x] = 0;
                }
            }
        }
        rep(i, N){
            if (d[i] != -1 && c[i] != d[i]) flag = false;
        }
        if (flag) {
            ans = max(ans, (ll)count(all(c), 1));
        }
        }
    cout << ans << endl;
}
