#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
// if(nextY >= 0 && nextY < H && nextX >= 0 && nextX < W)
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<ll> A(N+1);
    rep(i, N+1) cin >> A[i];
    auto B = A;
    per(i, N) {
        B[i] += B[i+1];
    }

    ll ans = 0, cur = 1;

    rep(i, N+1) {
        if(cur < A[i]) {
            cout << -1 << endl;
            return 0;
        }

        ans += cur;
        cur -= A[i];
        cur *= 2LL;
        chmin(cur, B[i+1]);
    }

    cout << ans << endl;
}
