//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi p(n);
    vector<ld> sum(n+1);
    rep(i, n) {
        cin >> p[i];
        sum[i+1] = sum[i] + (ld)(p[i]+1)/2;
    }

    ld ans = 0;
    rep(i, n-k+1) {
        ans = max(ans, sum[i+k]-sum[i]);
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
}