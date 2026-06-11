#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    vii a(3, vi(3));
    rep(i, 3) rep(j, 3) cin >> a.at(i).at(j);
    int n; cin >> n;
    vii b(3, vi(3));

    rep(i, n) {
        int x; cin >> x;
        rep(i, 3) rep(j, 3) if (a.at(i).at(j) == x)b.at(i).at(j) = 1;
    }

    bool ans = false;

    rep(i, 3) {
        int cnt = 0;
        rep (j, 3) cnt += b.at(i).at(j);
        if (cnt == 3) ans = true;
    }

    rep(i, 3) {
        int cnt = 0;
        rep (j, 3) cnt += b.at(j).at(i);
        if (cnt == 3) ans = true;
    }

    {
        int cnt = 0;
        rep (j, 3) cnt += b.at(j).at(j);
        if (cnt == 3) ans = true;
    }

    {
        int cnt = 0;
        rep (j, 3) cnt += b.at(j).at(2 - j);
        if (cnt == 3) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;


}