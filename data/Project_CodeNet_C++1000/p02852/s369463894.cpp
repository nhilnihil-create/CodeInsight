#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

template <typename T>
class SegmentTree {
   public:
    SegmentTree(vector<T> &base, function<T(T, T)> fn_, T e_) {
        fn = fn_;
        e = e_;
        n = 1;
        while (n < (int)base.size()) n *= 2;

        node.resize(2 * n - 1, e);
        REP(i, 0, base.size())
        node[n - 1 + i] = base[i];
        for (int i = n - 2; i >= 0; i--) node[i] = fn(node[2 * i + 1], node[2 * i + 2]);
    }

    // 0-origin
    void update(int i, T x) {
        i += n - 1;
        node[i] = x; // for update
        // node[i] += x // for addition
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = fn(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    // 0-origin, [a, b)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return node[k];

        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return fn(vl, vr);
    }

    void print(int w = 4) {
        int prev = 0;
        for (int i = 1; i <= n; i *= 2) {
            for (int j = prev; j < prev + i; j++) {
                cout << setw(n * w / i) << setfill(' ') << node[j];
            }
            cout << endl;
            prev += i;
        }
    }

   private:
    int n;
    vector<T> node;
    function<T(T, T)> fn;
    T e;
};

int main() {
    int N, M; string S; cin >> N >> M >> S;

    vector<int> base(N + 1, 1 << 29);
    base[N] = 0;
    auto fn = [](auto l, auto r){ return min(l, r); };
    SegmentTree<int> seg(base, fn, 1 << 29);

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '1') continue;
        seg.update(i, seg.query(i + 1, min(i + M + 1, N + 1)) + 1);
    }

    int cnt = seg.query(0, 1), prev = 0;
    if (cnt == 1 << 29) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, 1, N + 1) {
        int v = seg.query(i, i + 1);
        if (v != 1 << 29 && cnt != v) {
            cnt = v;
            cout << i - prev << endl;
            prev = i;
        }
    }

    return 0;
}