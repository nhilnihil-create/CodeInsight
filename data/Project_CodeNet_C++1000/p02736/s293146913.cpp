#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

template <class Abel> 
struct BinaryIndexTree {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0; // to be set
    
    /* [1, n] */
    BinaryIndexTree(int n) { init(n); }
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

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string A;
    cin >> n >> A;

    vector<int> X(n);
    rep(i, n) X[i] = A[i] - '0';
    int odd_cnt = 0;
    rep(i, n) {
        if (X[i] % 2 == 0) continue;
        if (((n - 1) & i) == i) ++odd_cnt;
    }
    if (odd_cnt % 2) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> cnt(3, 0);
    rep(i, n) {
        ++cnt[X[i] - 1];
    }
    if(cnt[1]) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, n) X[i] = (X[i] - 1) / 2;
    odd_cnt = 0;
    rep(i, n) {
        if (X[i] % 2 == 0) continue;
        if (((n - 1) & i) == i) ++odd_cnt;
    }
    if (odd_cnt % 2) cout << 2 << endl;
    else cout << 0 << endl;
    
    return 0;
}