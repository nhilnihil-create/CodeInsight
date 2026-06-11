// cout << "Case #" << test << ": ";
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
template <typename Mnd> struct segment_tree {
    int sz;
    vector<Mnd> data;
    function<Mnd(Mnd, Mnd)> f;
    Mnd e;
    //サイズだけ指定して初期化
    segment_tree(int _sz, function<Mnd(Mnd, Mnd)> _f, Mnd _e) : f(_f), e(_e) {
        sz = 1;
        while(sz < _sz)
            sz <<= 1;
        data.assign(sz * 2, e);
    }
    //参照渡しなので代入とかもできる
    Mnd &operator[](const int &k) { return data[k + sz]; }
    //木を構築 O(n)
    void build() {
        for(int i = sz - 1; i > 0; i--)
            data[i] = f(data[2 * i], data[2 * i + 1]);
    }
    //更新しつつ木を再構築 O(log n)
    void update(int k, Mnd x) {
        data[k += sz] = x;
        while(k >>= 1)
            data[k] = f(data[2 * k], data[2 * k + 1]);
    }
    //[a,b)でのクエリに答える　O(log n)
    Mnd query(int a, int b) const {
        Mnd l = e, r = e;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1)
                l = f(l, data[a++]);
            if(b & 1)
                r = f(r, data[--b]);
        }
        return f(l, r);
    }
};
int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    segment_tree<int> dpf(
        n, [](int a, int b) { return max(a, b); }, 0);
    segment_tree<int> dpb(
        n, [](int a, int b) { return max(a, b); }, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'o') {
            dpf.update(i, dpf.query(0, i - c) + 1);
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'o') {
            dpb.update(i, dpb.query(i + c + 1, n) + 1);
        }
    }
    for(int x = 0; x < n; x++) {
        if(s[x] == 'o' && dpf.query(0, x) + dpb.query(x + 1, n) >= k) {
            continue;
        } else if(s[x] != 'x') {
            cout << x + 1 << endl;
        }
    }
}
