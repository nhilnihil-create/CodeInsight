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
    ll N, D;
    cin >> N >> D;

    vector<vector<ll>> X(N, vector<ll>(D));
    REP(i, N) REP(j, D) cin >> X[i][j];

    vector<ll> sq(42);
    REP(i, sq.size()) {
        sq[i] = i*i;
    }

    ll ans = 0;
    vector<vector<ll>> dt2(N, vector<ll>(N, 0));
    REP(y, N) {
        FOR(z, y + 1, N) {
            REP(i, D) {
                dt2[y][z] += pow(X[y][i] - X[z][i], 2);
            }

            for(ll i = 0; i*i <= dt2[y][z]; ++i) {
                if(dt2[y][z] == i*i) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}