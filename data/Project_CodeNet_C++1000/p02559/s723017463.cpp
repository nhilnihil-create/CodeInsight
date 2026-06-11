#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct FenwickTree {
    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1) {}

    T sum(int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

    int lower_bound(T x) {
        if (x <= 0) return 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        int j = 0;
        for (; k > 0; k /= 2) {
            if (j + k <= n && data[j+k] < x) {
                x -= data[j+k];
                j += k;
            }
        }
        return j;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    FenwickTree<ll> ft(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ft.add(i, a);
    }
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            ft.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.sum(r - 1) - ft.sum(l - 1) << "\n";
        }
    }
}