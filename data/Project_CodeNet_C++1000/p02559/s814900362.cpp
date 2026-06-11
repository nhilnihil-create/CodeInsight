#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>
#include <atcoder/all>


using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;


#define REP(i, n) for(ll i = 0; i < n; i++)





















template <typename T>
class SegmentTree {
private:
    int n;    // 配列の要素数
    T init;    // 配列を初期化するときの値
    vector<T> data;     // セグメントツリーを持つ配列
    
public:
    SegmentTree(int m, T init = 0) : n(1), init(init){
        while(n < m) n <<= 1;
        data.assign(2 * n - 1, init);
    }
    
    T operation(T t1, T t2){
        return t1 + t2;
    }
    
    void update(int k, T val){
        k += n - 1;
        data[k] = val;
        
        while(k > 0){
            k = (k - 1) / 2;
            data[k] = operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    
    // [a, b) の値を求める
    T query(int a, int b){
        return query(a, b, 0, 0, n);
    }
    
    T query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b){
            return data[k];
        }
        else{
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return operation(vl, vr);
        }
    }
};


int main(){
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    SegmentTree<ll> tree(n);
    REP(i, n){
        cin >> a[i];
        tree.update(i, a[i]);
    }
    REP(i, Q){
        ll q;
        cin >> q;
        if(q == 0){
            ll p, x;
            cin >> p >> x;
            tree.update(p, tree.query(p, p + 1) + x);
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << tree.query(l, r) << endl;
        }
    }
}