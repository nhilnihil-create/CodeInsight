#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdarg>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;
#define INF 2e9 + 9
#define MOD 1000000007
#define ALL(v) v.begin() , v.end()
#define Int int64_t
#define pll pair<Int,Int>
template<class T> using pql = priority_queue<T, vector<T>>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define ll(n) Int n; cin >> n;
#define LL(...) Int __VA_ARGS___; cin >> __VA_ARGS___;
#define OUT(...) cout << __VA_ARGS___;
#define RP(n, i, s) for(Int i = s ;i < n ;i++)
#define REP(n, i) for (Int i = 0; i < n; i++)
#define REPe(n, i) for (Int i = 1; i <= n; i++)
#define RPe(n, i, s) for (Int i = s; i <= n; i++)
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;
#define upd_min(miner, updater) if (miner > updater) miner = updater;
#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus < 201703L
#        pragma GCC target("avx")
#    else
#        pragma GCC target("avx2")
#    endif

#endif
// 実数の場合
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

void ansYes(bool flag){
    if (flag) cout << "Yes" << endl; else  cout << "No" << endl;
}

void ansYES(bool flag){
    if (flag) cout << "YES" << endl; else  cout << "NO" << endl;
}

struct node {
    Int to;
    Int length;
};


vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return (ret);
}

int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};



//UnionFind群
/*
class UnionFind {
protected:
    vector<int> par;
    vector<int> data;
    int cnt;
public:
    UnionFind() : par(1), data(1), cnt(1) {};
    UnionFind(int N);
    int root(int x);
    int marge(int x, int y);
    bool same(int x, int y);
    int add();
    int add(int x);
    int solve();
    inline int getSize(int x) { return data.at(root(x)); };
};

UnionFind::UnionFind(int N) : par(N), data(N), cnt(N) {
    for (int i = 0; i < N; i++) {
        par.at(i) = -1;
        data.at(i) = 1;
    }
}


int UnionFind::root(int x) {
    if (par.at(x) == -1) return x;
    return par.at(x) = root(par.at(x)); // 経路圧縮
}

int UnionFind::marge(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return rx;
    else { // ノード数の少ない方に接続
        if (data.at(rx) < data.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        data.at(rx) += data.at(ry);
        return rx;
    }
    return rx;
}

bool UnionFind::same(int x, int y) {
    return root(x) == root(y);
}

int UnionFind::add() {
    par.push_back(cnt);
    cnt++;
    return cnt - 1;
}

int UnionFind::add(int x) {
    par.push_back(cnt);
    cnt++;
    return marge(x, cnt);
}

int UnionFind::solve() {
    for (int i = 0; i < cnt;i++) {
        if (par.at(i) == -1) {

        }
    }
}*/

/*
int dfs(Int par, Int maxs, bool ans) {
    if (mita.at(par) == 1) return 0;
    if (maxs > h.at(par)) {
        maxs = h.at(par);
        ans = true;
    }else if (maxs == h.at(par)){
        ans = false;
    }

    Int maxer = 0;
    for (auto z : to[par]){
        mita.at(par) = 1;
        maxer = dfs(z,maxs,ans);
    }
}*/

int main() {
    Int n, m;
    cin >> n >> m;
    vector<Int> sc(n,-1);
    REP(m,i){
        int sx, cx;
        cin >> sx >> cx;
        sx--;
        if (n != 1 && sx == 0 && cx == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (sc.at(sx) != -1 && sc.at(sx) != cx) {
            cout << -1 << endl;
            return 0;
        }
        sc.at(sx) = cx;
    }
        if (sc.at(0) == -1) {
            if (n == 1) {
                cout << 0 << endl;
                return 0;
            } else {
                sc.at(0) = 1;
            }
        }
    REP(n,i){
        cout << max((Int)0,sc.at(i));
    }
    cout << endl;

}