#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF = 1e13;

int main() {
    ll A, B, M;
    cin >> A >> B >> M;

    vector<ll> a(A), b(B), x(M), y(M), c(M);
    REP(i, A) cin >> a[i];
    REP(i, B) cin >> b[i];
    REP(i, M) {
        cin >> x[i] >> y[i] >> c[i];
        --x[i];
        --y[i];
    }

    ll ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
    REP(i, M) {
        ll tmp = a[x[i]] + b[y[i]] - c[i];
        if(tmp < ans) {
            ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}