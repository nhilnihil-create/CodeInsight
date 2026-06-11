#include <bits/stdc++.h>
// #include <set>
// #include <vector>
// #include <ostream>
// #include <atcoder/notall>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using VPII = std::vector<std::pair<int, int>>;
using PLL = std::pair<ll, ll>;
using VPLL = std::vector<std::pair<ll, ll>>;
using TI3 = std::tuple<int, int, int>;
using TI4 = std::tuple<int, int, int, int>;
using TL3 = std::tuple<ll, ll, ll>;
using TL4 = std::tuple<ll, ll, ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()
#define allpt_cr(v) (v).crbegin(), (v).crend()

const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod1;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";
const string alphabets = "abcdefghijklmnopqrstuvwxyz";

template <typename T>
void show1dvec(const vector<T> &v) {
    if (v.size() == 0) return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v) {
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v) {
    int n = v.size();
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s) {
    int n = v.size();
    rep(i, n) {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v) {
    T s = v[0];
    int n = v.size();
    rep(i, n - 1) {
        if (s > v[i + 1]) {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s) {
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

bool check(int y, int x, int h, int w) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

bool iskadomatsu(int a, int b, int c) {
    return (a != b && b != c && c != a) &&
           ((a > b && b < c) || (a < b && b > c));
}

double euc_dist(PII a, PII b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

VS split(string s, char c) {
    VS ret;
    string part;
    s += c;
    rep(i, s.length()) {
        if (s[i] == c) {
            if (part != "") ret.emplace_back(part);
            part = "";
        } else if (s[i] != c) {
            part += s[i];
        }
    }
    return ret;
}

template <typename T, typename S, typename R>
ll pow_mod(T p, S q, R mod = 1ll) {
    ll ret = 1, r = p;
    while (q) {
        if (q % 2) ret *= r, ret %= mod;
        r = (r * r) % mod, q /= 2;
    }
    return ret % mod;
}

template <typename T, typename S>
ll pow_no_mod(T p, S q) {
    ll ret = 1, r = p;
    while (q) {
        if (q % 2) ret *= r;
        r = (r * r), q /= 2;
    }
    return ret;
}

void make_frac_tables(VL &frac_list, VL &frac_inv_list) {
    rep(i, frac_list.size() - 1) {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
}

pair<VL, VL> make_frac_tables(int n) {
    VL frac_list(n + 1, 1), frac_inv_list(n + 1, 1);
    rep(i, n) {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
    return make_pair(frac_list, frac_inv_list);
}

ll comb(int a, int b, const VL &frac_list, const VL &frac_inv_list) {
    if (a < b) return 0;
    if (b < 0) return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[b];
    ret %= mod;
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}

void djkstra(int n, int s, int t, const vector<set<int>> &connect) {
    const int intm = 1e9;
    vector<int> shortest(n, intm);
    shortest[s] = 0;
    vector<int> search = {s};
    vector<int> new_search;
    while (!search.empty()) {
        for (auto i : search) {
            for (auto j : connect[i]) {
                if (shortest[j] > 1 + shortest[i]) {
                    shortest[j] = 1 + shortest[i];
                    new_search.emplace_back(j);
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
        // show1dvec(search);
        // show1dvec(shortest);
    }
    if (shortest[t] == intm) shortest[t] = -1;
    printf("%d\n", shortest[t]);
}

struct node {
    int parent = -1;
    ll weight = 0;
    int depth = 0;
    int subtree = 0;
    VPII children;
    VPII connect;
    node(int n) {
        parent = -1;
        weight = 0;
        depth = 0;
        subtree = 0;
        children;
        connect;
    }
};

struct graph {
    int _n;
    int root = 0;
    vector<node> nodes;
    graph(int n) {
        _n = n;
        rep(i, _n) nodes.emplace_back(node(_n));
    }
    void showparent() {
        rep(i, _n - 1) cout << nodes[i].parent << wsp;
        cout << nodes[_n - 1].parent << rt;
    }
    void showweight() {
        rep(i, _n - 1) cout << nodes[i].weight << wsp;
        cout << nodes[_n - 1].weight << rt;
    }
    void showsubtree() {
        rep(i, _n - 1) cout << nodes[i].subtree << wsp;
        cout << nodes[_n - 1].subtree << rt;
    }
    void showdepth() {
        rep(i, _n - 1) cout << nodes[i].depth << wsp;
        cout << nodes[_n - 1].depth << rt;
    }
};



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // リアクティブ問題のときはコメントアウト

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif

    int n, y, x;
    cin >> n;
    VI xplusy, xminusy;
    rep(i, n) {
        cin >> x >> y;
        xplusy.emplace_back(x + y);
        xminusy.emplace_back(x - y);
    }

    cout << max(*max_element(allpt_c(xplusy)) - *min_element(allpt_c(xplusy)),
                *max_element(allpt_c(xminusy)) - *min_element(allpt_c(xminusy)))
         << rt;

    return 0;
}
