//(UNCOMMENT WHEN SUBMITTING)
//#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

// clang-format off
#define range(i) for (int _ = 0; _ < i; _++)
#define vprnt(v) for (auto vi : v) cout << vi << " "; cout << endl;
#define fastio() ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace ::std;
int nxt() {int x;cin >> x;return x;}
ll nxtll() {ll x;cin >> x;return x;}
// clang-format on

int main() {
    fastio();
    ll H = nxtll(), W = nxtll(), M = nxtll();

    ll rowsums[H] = {0};
    ll colsums[W] = {0};

    set<ll> bombs;

    for (ll i = 0; i < M; i++) {
        ll hi, wi;
        cin >> hi >> wi;
        hi--;
        wi--;
        bombs.emplace(hi + wi * H);
        rowsums[hi]++;
        colsums[wi]++;
    }

    vector<pair<ll, ll>> rowv;
    vector<pair<ll, ll>> colv;

    for (ll i = 0; i < H; i++) {
        rowv.push_back(make_pair(rowsums[i], i));
    }
    for (ll i = 0; i < W; i++) {
        colv.push_back(make_pair(colsums[i], i));
    }

    sort(all(rowv));
    sort(all(colv));

    reverse(all(rowv));
    reverse(all(colv));

    vector<ll> maxrows, maxcols;

    for (ll i = 0; i < rowv.size(); i++) {
        if (rowv[i].first == rowv[0].first) {
            maxrows.push_back(rowv[i].second);
        } else {
            break;
        }
    }

    for (ll i = 0; i < colv.size(); i++) {
        if (colv[i].first == colv[0].first) {
            maxcols.push_back(colv[i].second);
        } else {
            break;
        }
    }

    for (ll row : maxrows) {
        for (ll col : maxcols) {
            if (bombs.find(row + col * H) == bombs.end()) {
                cout << colsums[col] + rowsums[row] << endl;
                return 0;
            }
        }
    }

    cout << colv[0].first + rowv[0].first - 1LL << endl;
    return 0;
}
