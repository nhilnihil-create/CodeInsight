#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {
    }
    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    reverse(all(s));
    vector<int> ans;
    int pos = 0;
    while (pos < n) {
        bool ok = 0;
        for (int i = m; i >= 1; i--) {
            if (s[pos + i] == '0') {
                ok = 1;
                pos += i;
                ans.push_back(i);
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(all(ans));
    for (int x : ans) cout << x << endl;
}