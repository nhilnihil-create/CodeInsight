#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n = 0) : n(n), d(n + 1) {}
    void add(int i, T x = 1) {
        for(i++; i <= n; i += i & -i) {
            d[i] += x;
        }
    }

    T sum(int i) {
        T x = 0;
        for(i++; i; i -= i & -i) {
            x += d[i];
        }
        return x;
    }

    T sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    BIT<long long> tree(n);
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        tree.add(i, x);
    }
    for(int i = 0; i < q; i++) {
        long long x, a, b;
        cin >> x >> a >> b;
        if(x == 0) tree.add(a, b);
        else cout << tree.sum(a, b) << endl;;
    }
    return 0;
}
