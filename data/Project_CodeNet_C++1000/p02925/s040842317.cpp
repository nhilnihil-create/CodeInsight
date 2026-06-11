#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

struct Game {
    int i, j, date;
    Game(int i, int j, int date) : i(i), j(j), date(date) {}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vvi a(n, vi(n - 1));
    rep(i, 0, n) {
        rep(j, 0, n - 1) {
            int x;
            cin >> x;
            a[i][j] = x - 1;
        }
    }

    // 初日に出来る試合をキューにプッシュ．
    queue<Game> q;
    rep(i, 0, n) {
        if (i < a[i][0] && a[a[i][0]][0] == i) { q.emplace(i, a[i][0], 1); }
    }

    // 全試合数，日数．
    int cnt = 0, date = 0;

    // 各プレイヤーの終了した試合数．
    vi done(n, 0);

    while (!q.empty()) {
        Game g = q.front();
        q.pop();

        ++cnt;
        ++done[g.i];
        ++done[g.j];
        date = max(date, g.date);

        // g.iが翌日に試合出来るかどうか．
        if (done[g.i] != n - 1) {
            int j = a[g.i][done[g.i]];
            if (a[j][done[j]] == g.i) { q.emplace(g.i, j, g.date + 1); }
        }

        // g.jが翌日に試合出来るかどうか．
        if (done[g.j] != n - 1) {
            int i = a[g.j][done[g.j]];
            if (a[i][done[i]] == g.j) { q.emplace(i, g.j, g.date + 1); }
        }
    }

    if (cnt != n * (n - 1) / 2) {
        cout << -1 << endl;
    } else {
        cout << date << endl;
    }

    return 0;
}