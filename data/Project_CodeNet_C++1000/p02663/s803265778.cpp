#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
//
//class UnionFind {
//private:
//    int sz;
//    vector<int> par, size_;
//public:
//    UnionFind(){}
//    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
//        iota(par.begin(), par.end(), 0);
//    }
//    int find(int x){
//        if(par[x] == x) return x;
//        else return par[x] = find(par[x]);
//    }
//    void unite(int x, int y){
//        x = find(x); y = find(y);
//        if(x == y) return;
//        if(size_[x] < size_[y]) swap(x,y);
//        par[y] = x;
//        size_[x] += size_[y];
//    }
//    int size(int x){
//        x = find(x);
//        return size_[x];
//    }
//    bool same(int x, int y){
//        return find(x) == find(y);
//    }
//};
//void no(){
//    cout << "Impossible" << endl;
//    exit(0);
//}
//int main(){
//    cin.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> g(n);
//    vector<int>a(n);
//    rep(i,n)cin >> a[i];
//    rep(i,m){
//        int x, y;
//        cin >> x >> y;
//        x--;y--;
//        g[x].push_back(y);
//        g[y].push_back(x);
//    }
//    if(m == n - 1){
//        cout << 0 << endl;
//        return 0;
//    }
//    if(n / 2 < n - m - 1){
//        no();
//    }
//}
int main(){
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    if(b > d){
        cout << (c - a - 1) * 60 + (60 - b + d) - k << endl;
    }else{
        cout << (c - a) * 60 + (d - b) - k << endl;
    }
}
