#include<bits/stdc++.h>

#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template<typename X, typename T>
auto vectors(X x, T a) {
    return vector<T>(x, a);
}

template<typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
    auto cont = vectors(y, z, zs...);
    return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x: v) { is >> x; }
    return is;
}

template<typename T>
class CumulativeSum {
    vector<T> a;
public:
    CumulativeSum(vector<T> &x) : a(x.size() + 1, 0) {
        rep(i, x.size()) {
            a[i + 1] = a[i] + x[i];
        }
    }

    T get(int l, int r) { // [l, r]の区間の合計を求める
        return a[r + 1] - a[l];
    }

    T operator[](const int i) const {
        return a[i];
    }
};


bool C(int mid, int k, int n, vector<int> &a, CumulativeSum<int> &sum) {
    int d = distance(a.begin(), lower_bound(all(a), mid));
    int total = sum.get(0, d - 1) + (a.size() - d) * mid;
    //show(d)show(total)show(mid*k)
    return total >= mid * k;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(300005, 0);
    rep(i, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    sort(all(a));

    CumulativeSum<int> sum(a);

    range(k, 1, n + 1) {
        int right = n + 1, left = 0;
        rep(i, 100) {
            int mid = (right + left) / 2;
            if (C(mid, k, n, a, sum)) left = mid;
            else right = mid;
        }
        cout << left << endl;
    }
}