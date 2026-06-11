/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.09.09 02:35:30
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;



template< typename T >
struct BinaryIndexedTree {
    std::vector< T > data;
    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }
    
    inline T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    
    inline T sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
    
    
    inline void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    
    int lower_bound(ll k) {
        if (k <= 0) return 0;
        int res = 0;
        int N = 1; while (N < (int)data.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)data.size() && data[res + i] < k) {
                k -= data[res + i];
                res += i;
            }
        }
        return res;
    }
    void print() {
        std::cout << "[ ";
        for (int i = 0; i < data.size() - 1; i++) {
            std::cout << sum(i, i);
            if (i < data.size() - 2) cout << ", ";
        }
        std::cout << " ]" << endl;
    }
};
int main() {
    int n,q;cin >> n >> q;
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        int a;cin >> a;
        bit.add(i,a);
    }
    while(q--) {
        int t;cin >> t;
        if (t == 0) {
            int p,x;cin >> p >> x;
            bit.add(p,x);
        }
        else {
            int l,r;cin >> l >> r;
            cout << bit.sum(l,r-1) << endl;
        }
    }
    return 0;
}