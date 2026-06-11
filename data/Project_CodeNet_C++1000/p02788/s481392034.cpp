#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 区間加算にも対応した BIT
template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

using pll = pair<long long, long long>;
int N;
long long D, A;
vector<long long> X, H;

long long solve() {
    // モンスターを X が小さい順に
    vector<int> ids(N);
    for (int i = 0; i < N; ++i) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) {
            return X[i] < X[j]; });
    vector<long long> nX(N), nH(N);
    for (int i = 0; i < N; ++i) nX[i] = X[ids[i]], nH[i] = H[ids[i]];
    X = nX, H = nH;

    // BIT で処理していく
    BIT<long long> bit(N+10);
    for (int i = 0; i < N; ++i) bit.add(i+1, i+2, H[i]); // 初期化
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        long long cur = bit.sum(i+1, i+2);
        if (cur <= 0) continue;

        // モンスター i を倒すのに必要な回数
        long long need = (cur + A - 1) / A;

        // X[i] を左端とした爆発が届く範囲を求める
        long long right = X[i] + D * 2;
        int id = upper_bound(X.begin(), X.end(), right) - X.begin();

        // 爆発させる
        bit.add(i+1, id+1, -need * A);
        res += need;
    }
    return res;
}

int main() {
    cin >> N >> D >> A;
    X.resize(N); H.resize(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> H[i];
    cout << solve() << endl;
}