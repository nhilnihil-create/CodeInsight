#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define all(v) v.begin(), v.end() // sort(all(array))
#define INF 1000000000
#define mod 1000000007
using namespace std;
using ll = long long;
using vi = vector<int>; //vi array(要素数, 初期値)
using vll = vector<ll>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>; //vvi table(行数, vi(列数, 初期値))
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;

int main() {
    int n; cin >> n;
    vll A(n); rep(i, n) cin >> A[i];
    ll inf = 1000000000000000000;

    if (count(all(A), 0)) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep(i, n) {
        if (A[i] <= inf / ans) {
        /*これまでの積にA[i]をかけても 
        オーバーフローしなければかけ算*/
            ans *= A[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}