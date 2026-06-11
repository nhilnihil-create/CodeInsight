#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long;
using namespace std;

const ll mod = 1000000007;

template <class Abel> struct BIT2D {
    int H, W;
    vector<vector<Abel>> data;
    Abel UNITY = 0;

    BIT2D(int H_, int W_) { init(H_, W_); }
    void init(int H_, int W_) {
        H = H_ + 1; W = W_ + 1;
        data.assign(H, vector<Abel>(W, UNITY));
    }
 
    void add(int h, int w, Abel x) {
        for (int i = h; i < H; i += i & -i) {
            for (int j = w; j < W; j += j & -j) {
                data[i][j] += x;
                data[i][j] %= mod;
            }
        }
    } // 1-index
    Abel sum(int h, int w) {
        Abel res = UNITY;
        for (int i = h; i > 0; i -= i & -i) {
            for (int j = w; j > 0; j -= j & -j) {
                res += data[i][j];
                res %= mod;
            }
        }
        return res;
    } // 1-index
    /*
    Abel query(int h1, int w1, int h2, int w2) {
        return sum(h2-1, w2-1) - sum(h2-1, w1-1) - sum(h1-1, w2-1) + sum(h1-1, w1-1);
    } // [h1,h2) * [w1,w2) 1-index
    */
};

int main(){
    int n, m; cin >> n >> m;
    vector<int> s(n); rep(i,n) cin >> s[i];
    vector<int> t(m); rep(i,m) cin >> t[i];

    BIT2D<ll> dp(n,m);
    rep(i,n) rep(j,m) if(s[i] == t[j]) dp.add(i+1,j+1,dp.sum(i,j)+1);
    cout << dp.sum(n,m) + 1 << endl;
    return 0;
}