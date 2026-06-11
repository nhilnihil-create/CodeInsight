#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

template <typename T>
struct BIT_tree{
    int n;  // 配列の要素数(数列の要素数+1)
    vector<T> bit; // データの格納先(1-indexed)。初期値は0
    BIT_tree(vector<T> v){
        n = v.size() + 1;
        bit.assign(n, 0);
        int i;
        for(i = 0;i < v.size();++i){
            add(i, v.at(i));
        }
    }
    
    //0-indexedで受け取り, 内部は1-indexedで作動
    void add(int i, T x){
        ++i;
        int ind;
        for(ind = i;ind < n;ind += (ind & -ind)){
            bit.at(ind) += x;
        }
    }
    
    //1-indexedで作動
    T sum_sub(int i){
        T s = 0;
        int idx;
        for(idx = i;idx > 0;idx -= (idx & -idx)){
            s += bit.at(idx);
        }
        return s;
    }
    
    //0-indexedで受け取り, [l, r)に加算, 1-indexedで渡す
    T sum(int l, int r){
        return sum_sub(r) - sum_sub(l);
    }
    
    ll lower_bound(T w){
        if(w < 0) return -1;
        int x = 0, r = 1;
        while(r < n) r = r<<1;
        int len;
        for(len = r;len > 0;len = len >> 1){
            if(x + len < n && bit.at(x + len) < w){
                w -= bit.at(x+len);
                x += len;
            }
        }
        return x;
    }
};

int main()
{
    ll i,j;
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    BIT_tree<ll> bit(a);
    rep(i,q){
        ll c;
        cin >> c;
        if(c == 0){
            ll p,x;
            cin >> p >> x;
            bit.add(p, x);
        }else{
            ll l,r;
            cin >> l >> r;
            cout << bit.sum(l,r) << endl;
        }
    }

    return 0;
}