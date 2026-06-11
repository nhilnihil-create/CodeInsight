#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

const int MAX_ROW = 110;
const int MAX_COL = 100005;

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

/*
int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]); // これしたらあかんってこと？ 何bit目か大事
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}
*/
 
int n;

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H, 0);
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = 0; row < A.H; ++row) {
            if (used[row]) continue;
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        // cout << col << " " << pivot << endl;
        if (pivot == -1) continue;
        for (int row = 0; row < A.H; ++row) {
            if (row != pivot && A[row][col]) A[row] ^= A[pivot]; // 行全体にxor
        }
        used[pivot] = true;
        
        // cout << endl; rep(i, 60) { rep(j, n + 1) cout << A[i][j] << " "; cout << endl; }
    }
    
}


// http://drken1215.hatenablog.com/entry/2019/09/16/213700

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<int> odd(61);
    ll res = 0;
    BitMatrix B(61, n + 1); // 拡大係数行列の分
    
    for (ll i = 60; i >= 0; --i) {
        int cnt = 0;
        rep(j, n) {
            if (a[j] & (1LL << i)) cnt++;
        }
        if (cnt & 1) {
            odd[i] = 1;
            res += (1LL << i);
        } else if (cnt == 0) { // 拡大係数行列0だから別
            odd[i] = 1;
        } else {
            // 行列作る
            rep(j, n) {
                if (a[j] & (1LL << i)) B[60 - i][j] = 1;
            }
            B[60 - i][n] = 1;
        }
        
    }
    // cout << B.W << endl;
    // cout << endl; rep(i, 60) { rep(j, n + 1) cout << B[i][j] << " "; cout << endl; }
    
    GaussJordan(B, true);
    // cout << endl; rep(i, 60) { rep(j, n + 1) cout << B[i][j] << " "; cout << endl; }
    
    for (int i = 60; i >= 0; --i) {
        if (odd[i]) continue;
        bool ok = false; // 左辺0なのに右辺非0
        rep(j, n) if (B[60 - i][j]) ok = true;
        if (!B[60 - i][n]) ok = true;
        if (ok) { /* cout << i << endl; */ res += (2LL << i); }
    }
    cout << res << endl;
}
    
