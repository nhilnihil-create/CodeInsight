#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

template <typename T>
struct BIT_tree{

    public:
        BIT_tree(vector<T> v) : _n(v.size()), data(v.size(), 0){
            for(int i = 0;i < _n;++i){
                add(i, v[i]);
            }
        }
    
        //0-indexedで受け取り, 内部は1-indexedで作動
        void add(int i, T x){
            ++i;
            while(i <= _n){
                data[i-1] += x;
                i += i & -i;
            }
        }
        
        //0-indexedで受け取り, [l, r)に加算, 1-indexedで渡す
        T sum(int l, int r){
            return sum(r) - sum(l);
        }
        
        ll lower_bound(T w){
            if(w < 0) return -1;
            int x = 0, r = 1;
            while(r < _n) r = r<<1;
            int len;
            for(len = r;len > 0;len = len >> 1){
                if(x + len < _n && data[x + len] < w){
                    w -= data[x+len];
                    x += len;
                }
            }
            return x;
        }

    private:
        int _n;
        std::vector<T> data;

        T sum(int r){
            T s = 0;
            while(r > 0){
                s += data[r-1];
                r -= r & -r;
            }
            return s;
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
            ll l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }

    return 0;
}