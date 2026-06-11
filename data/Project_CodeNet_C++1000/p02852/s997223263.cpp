#include <bits/stdc++.h>

using namespace std;


using i64 = long long;

template<typename T>
struct Segtree{
    int n;
    T op;
    vector<T> elm;
    function<T(T, T)> f;

    Segtree(int n, T init, function<T(T, T)> f, T op = T()) :
        n(n),
        op(op),
        elm(2 * n, init),
        f(f)
    {
        for(int i = n - 1; i >= 1; --i)
            elm[i] = f(elm[2 * i], elm[2 * i + 1]);
    }

    Segtree(int n, vector<T> init, function<T(T, T)> f, T op = T()) :
        n(n),
        op(op),
        elm(2 * n),
        f(f)
    {
        for(int i = 0; i < n; ++i)
            elm[i + n] = init[i];
        for(int i = n - 1; i >= 1; --i)
            elm[i] = f(elm[2 * i], elm[2 * i + 1]);
    }

    void set(int x, T val){
        x += n;
        elm[x] = val;
        while(x >>= 1)
            elm[x] = f(elm[2 * x], elm[2 * x + 1]);
    }

    void update(int x, T val){
        x += n;
        elm[x] = f(elm[x], val);
        while(x >>= 1)
            elm[x] = f(elm[2 * x], elm[2 * x + 1]);
    }

    T get(int x, int y) const{
        T l = op, r = op;
        for(x += n, y += n - 1; x <= y; x >>= 1, y >>= 1){
            if(x & 1)
                l = f(l, elm[x++]);
            if(!(y & 1))
                r = f(elm[y--], r);
        }
        return f(l, r);
    }
};


signed main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> nex(n + 1, -1);
    Segtree<pair<int,int>> seg(n + 1, make_pair(int(1e9), int(1e9)), [](auto x, auto y){return min(x, y);},make_pair(int(1e9), int(1e9)) );
    seg.set(n, make_pair(0, n));
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '1')
            continue;
        auto res = seg.get(1 + i, min(i + 1+m, n + 1));
        seg.set(i, make_pair(res.first + 1, i));
        nex[i] = res.second;
    }
    if(seg.get(0, 1).first >= 1e9){
        cout << -1 << endl;return 0;
    }
    int i = 0;
    vector<int> w;
    while(i != n){
        w.emplace_back(nex[i] - i);
        i = nex[i];
    }
    for(int i = 0; i < w.size(); ++i)
        cout << w[i] << " \n"[i == w.size() - 1];

}
