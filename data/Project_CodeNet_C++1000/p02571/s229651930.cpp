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
    string s, t;
    cin >> s >> t;
    int ans = INF;
    rep(i, s.size() - t.size() + 1) {
        int cnt = 0;
        rep(j, t.size()) {
            if (s[i + j] != t[j]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    if (ans == INF) cout << 0 << endl;
    else cout << ans << endl;
}