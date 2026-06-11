#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

constexpr int MAX_ROW = 110;
constexpr int MAX_COL = 110000;
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL> &operator[](const int &i) { return val[i]; }
};

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H, 0);
    rep(col, A.W) {
        if(is_extended && col == A.W - 1) break;
        int pivot = -1;
        rep(row, A.H) {
            if(used[row]) continue;
            if(A[row][col]) {
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;
        rep(row, A.H) if(row != pivot && A[row][col]) A[row] ^= A[pivot];
        used[pivot] = true;
    }
}

const int MD = 60;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll res = 0;
    BitMatrix B(MD + 1, N + 1);
    vector<bool> cannot(MD + 1, 0);
    for(ll d = MD; d >= 0; d--) {
        int num = 0;
        rep(i, N) num += A[i] >> d & 1;
        if(num == 0) {
            cannot[d] = 1;
            continue;
        } else if(num & 1) {
            cannot[d] = 1;
            res += 1LL << d;
            continue;
        }
        rep(i, N) if(A[i] >> d & 1) B[MD - d][i] = 1;
        B[MD - d][N] = 1;
    }
    GaussJordan(B, true);

    for(int d = MD; d >= 0; d--) {
        if(cannot[d]) continue;
        bool ok = false;
        rep(i, N) if(B[MD - d][i]) ok = true;
        if(!B[MD - d][N]) ok = true;
        if(ok) res += 2LL << d;
    }

    cout << res << endl;

    return 0;
}