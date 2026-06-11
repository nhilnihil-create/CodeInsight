#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N;
    cin >> N;

    vector<ll> a(N);
    REP(i, N) {
        cin >> a[i];
    }

    vector<ll> a_cnt(N);
    vector<vector<pair<ll, ll>>> id_cnts(N + 1);
    id_cnts.at(0).emplace_back(make_pair(-1, 0));
    REP(i, a.size()) {
        ll tmp = INF;
        REP(j, id_cnts.at(a[i] - 1).size()) {
            ll tmp_sum = id_cnts[a[i] - 1][j].second;
            tmp_sum += i - id_cnts[a[i] - 1][j].first - 1;
            chmin(tmp, tmp_sum);
        }
        a_cnt[i] = tmp;
        id_cnts.at(a[i]).emplace_back(make_pair(i, a_cnt[i]));
    }

    ll ans = INF;
    REP(i, a.size()) {
        chmin(ans, a_cnt[i] + (N - i - 1));
    }
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}