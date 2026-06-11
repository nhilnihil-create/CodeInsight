#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N;
    cin >> N;

    vector<ll> B(N - 1);
    REP(i, B.size()) {
        cin >> B[i];
    }

    vector<ll> A(N);
    A[0] = B[0];
    A[A.size() - 1] = B[B.size() - 1];
    FOR(i, 1, A.size() - 1) {
        A[i] = min(B[i - 1], B[i]);
    }

    ll ans = 0;
    REP(i, A.size()) {
        ans += A[i];
    }
    cout << ans << endl;

    return 0;
}