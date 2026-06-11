#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    const T e;
    const F f;
    size_t sz;
    vector<T> tree;

    SegmentTree(size_t n, const F &f, const T &e = 0) : f(f), e(e) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(2*sz, e);
    }

    void set(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
        copy(begin, end, tree.begin() + sz);
        for(size_t k=sz-1; k>0; k--)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    void update(size_t k, const T &x) {
        k += sz;
        tree[k] = x;
        while(k >>= 1)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    T query(size_t a, size_t b) const {
        T l = e, r = e;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) l = f(l, tree[a++]);
            if(b & 1) r = f(tree[--b], r);
        }
        return f(l, r);
    }

    T operator[](const size_t k) const {
        return tree[sz + k];
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll nn = 1ll<<n;
    vector<ll> s(nn);
    for(auto &e: s) cin >> e;

    sort(s.begin(), s.end());

    ll p = s[0];
    s[0] = 1;
    for(ll i=1; i<nn; i++)
        if(s[i] == p)
            s[i] = s[i-1];
        else
            p = s[i], s[i] = 1 + s[i-1];

    ll m = s[nn-1];

    SegmentTree<long> st(m+1, [&](long a, long b){return a + b;}, 0);
    for(ll i=0; i<nn; i++)
        st.update(s[i], st[s[i]]+1);

    vector<ll> ss;
    ss.push_back(m);
    st.update(m, st[m]-1);
    for(ll i=0; i<n; i++) {
        vector<ll> pre = ss;
        for(auto &v: pre) {
            // [ok, v)にスライムがいる
            ll ok = 0, ng = v;
            while(abs(ok - ng) > 1) {
                ll mid = (ok + ng)/2;
                (st.query(mid, v) > 0 ? ok : ng) = mid;
            }
            if(!st.query(ok, v)) {
                cout << "No" << endl;
                return 0;
            }
            st.update(ok, st[ok]-1);
            ss.push_back(ok);
        }
    }
    cout << "Yes" << endl;
}
