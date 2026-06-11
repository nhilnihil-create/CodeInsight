#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){   // sum of [0, i)
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    BIT<ll> bit(n);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        bit.add(i, a);
    }
    while(q--){
        int t;
        cin >> t;
        if(t){
            int l, r;
            cin >> l >> r;
            cout << bit.sum(r) - bit.sum(l) << endl;;
        }
        else{
            int p;
            ll x;
            cin >> p >> x;
            bit.add(p, x);
        }
    }
}
