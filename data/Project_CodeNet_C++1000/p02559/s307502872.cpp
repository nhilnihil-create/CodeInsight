#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

template <class T> struct BIT {
    vector<T> dat;

    BIT(int n) {
        dat.resize(n + 1);
        for(int i = 0; i < (int)dat.size(); i++)
            dat[i] = 0;
    }
    BIT(vector<T> &vec) {
        dat.resize(vec.size() + 1);
        for(int i = 0; i < vec.size(); i++) {
            add(i + 1, vec[i]);
        }
    }

    // a is 1-indexed
    void add(int a, T x) {
        for(int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    // [1,a], a is 1-indexed
    T sum(int a) {
        T res = 0;
        for(int i = a; i > 0; i -= i & -i) {
            res = res + dat[i];
        }
        return res;
    }

    // [a,b), a and b are 1-indexed
    T sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

    // k-th number (k is 1-indexed)
    // lower_bound
    int get(int k) {
        if(k <= 0)
            return 0;
        int res = 0;
        int N = 1;
        while(N < (int)dat.size())
            N *= 2;
        for(int i = N / 2; i > 0; i /= 2) {
            if(res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    BIT<ll> bit(A);
    rep(i, Q) {
        int q;
        cin >> q;
        if(q == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p + 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            l++, r++;
            cout << bit.sum(l, r) << endl;
        }
    }
}