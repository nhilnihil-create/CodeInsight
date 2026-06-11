#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; i++)
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#ifdef _DEBUG
#define PRE_COMMAND             \
    std::cin.rdbuf(in.rdbuf()); \
    std::cout << fixed << setprecision(15);
#else
#define PRE_COMMAND cout << fixed << setprecision(15);
#endif
const double EPS = 1e-10, PI = acos(-1.0);
template <class T> auto MAX(T& seq) {
    return *max_element(seq.begin(), seq.end());
}
template <class T> auto MIN(T& seq) {
    return *min_element(seq.begin(), seq.end());
}
template <class T> auto SUM(T& seq) {
    T temp{0};
    auto& temp2 = temp[0];
    return accumulate(seq.begin(), seq.end(), temp2);
}
template <class T> void SORT(T& seq) { sort(seq.begin(), seq.end()); }
template <class T, class S> void SORT(T& seq, S& sort_order) {
    sort(seq.begin(), seq.end(), sort_order);
}
template <class T> void SORTR(vector<T>& seq) {
    sort(seq.begin(), seq.end(), greater<T>());
}
template <class T, class S, class R> long long pow(T n_0, S k_0, R mod_0) {
    long long n = n_0 % mod_0, k = k_0, mod = mod_0, now = 1;
    while (k) {
        if (k & 1) now = (now * n) % mod;
        n = (n * n) % mod;
        n >>= 1;
    }
    return now;
}
template <typename T> istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}

struct unionfind {  // size:要素数,tree：unionfind木
    int n;
    vector<int> tree_leader, tree_size;
    unionfind(int temp) : n(temp) {
        tree_leader.assign(n, 0);
        tree_size.assign(n, 1);
        for (int i = 0; i < n; i++) { tree_leader[i] = i; }
    }
    //結合
    void merge(int index1, int index2) {
        int l1 = leader(index1), l2 = leader(index2);
        if (l1 != l2) {
            if (tree_size[l1] <= tree_size[l2]) {
                tree_leader[l1] = l2;
                tree_size[l2] = tree_size[l1] + tree_size[l2];
            } else {
                tree_leader[l2] = l1;
                tree_size[l1] = tree_size[l1] + tree_size[l2];
            }
        }
    }
    //同じか判定
    bool same(int index1, int index2) {
        return leader(index1) == leader(index2);
    }
    // leaderを探す
    int leader(int index) {
        vector<int> temp_list(0);
        int temp = tree_leader[index];
        while (index != temp) {
            temp_list.push_back(index);
            index = temp;
            temp = tree_leader[index];
        }
        for (int i : temp_list) { tree_leader[i] = index; }
        return index;
    }
    // 連結成分のサイズ
    int size(int index) { return tree_size[leader(index)]; }
    // 「一つの連結成分の頂点番号のリスト」のリスト
    vector<vector<int>> groups() {
        int cnt = -1;
        vector<int> id_list(n, -1);
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int l = leader(i);
            if (id_list[l] == -1) {
                id_list[l] = ++cnt;
                ret.push_back({i});
            } else {
                ret[id_list[l]].push_back(i);
            }
        }
        return ret;
    }
    // 連結成分の個数
    int component() { return (int)groups().size(); }
};

// unionfindも呼び出す必要あり
// n:サイズ、abc:a→bで重みcの辺（0-indexed）
template <class T> auto Kruskal(int n, vector<tuple<int, int, T>> abc) {
    unionfind uf(n);
    vector<tuple<int, int>> ret(0);
    int weight_sum = 0;
    sort(abc.begin(), abc.end(),
         [](const auto& x, const auto& y) { return get<2>(x) < get<2>(y); });
    for (tuple<int, int, T> temp : abc) {
        int a, b;
        T c;
        tie(a, b, c) = temp;
        if (uf.same(a, b) == false) {
            ret.push_back(make_tuple(a, b));
            weight_sum += c;
            uf.merge(a, b);
        }
    }
    // return ret; // 最小全域木自体を出力する
    return weight_sum;
}

// 一点更新・一点取得の加法BIT
template <class num_type> struct BIT {
    int n;
    vector<num_type> bit;
    num_type allsum;
    int maxbit = 1;
    BIT(int tmp) : n(tmp) {
        bit.assign(n + 1, 0);
        allsum = 0;
        while (maxbit * 2 <= n) { maxbit *= 2; }
    }

    // 初期化する
    void make_bit(auto& a) {
        for (int i = 0, sz = (int)a.size(); i < sz; i++) {
            auto v = a[i];
            auto idx = i + 1;
            allsum += v;
            while (idx < n + 1) {
                bit[idx] += v;
                idx += idx & (-idx);
            }
        }
    }

    // 位置idxに値vを足す
    void add(auto idx, auto v) {
        idx++;
        allsum += v;
        while (idx < n + 1) {
            bit[idx] += v;
            idx += idx & (-idx);
        }
    }

    // 位置0からidxまでの和(sum(bit[:idx]))を計算する
    num_type sum(auto idx) {
        num_type ret = bit[0];
        while (idx > 0) {
            ret += bit[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }

    // 位置idx1からidx2までの和(sum(bit[idx1:idx2]))を計算する
    num_type sum(auto idx1, auto idx2) { return sum(idx2) - sum(idx1); }

    // 和がw以上となる最小のインデックスを求める
    int lowerbound(auto w) {
        if (w <= 0) { return 0; }
        int x = 0;
        int k = maxbit;
        while (k) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
            k /= 2;
        }
        return x;
    }
};

int main() {
    PRE_COMMAND
    ll n, q, t, p, x;
    cin >> n >> q;
    vector<ll> a(n);
    cin >> a;
    BIT<ll> bit(n);
    bit.make_bit(a);
    REP(i, q) {
        cin >> t >> p >> x;
        if (t == 0) bit.add(p, x);
        if (t == 1) cout << bit.sum(p, x) << endl;
    }
}