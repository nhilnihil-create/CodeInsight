#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

vector<P> en;

int main() {
    lint n, d, a;
    cin >> n >> d >> a;
    vec x(n), h(n);
    rep(i, n) cin >> x[i] >> h[i];

    en.resize(n);
    rep(i, n) en[i] = make_pair(x[i], h[i]);

    sort(all(en));

    lint res = 0;
    lint cur = 0;
    queue<pair<lint, lint>> que;

    rep(i, n) {
        lint x = en[i].first;
        lint h = en[i].second;

        while (!que.empty() && que.front().first < x) {
            cur -= que.front().second;
            que.pop();
        }

        h -= cur;
        if (h > 0) {
            lint c = (h+a-1) / a;
            res += c;
            lint damage = a * c;
            cur += damage;
            que.push(make_pair(x + d * 2, damage));
        }
    }

    cout << res << endl;

    return 0;
}