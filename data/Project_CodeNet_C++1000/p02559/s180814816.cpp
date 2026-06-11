#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n=0){
        initialize(n);
    }

    void initialize(int nin){
        n = nin;
        dat.assign(n, 0);
    }

    T sum(int i){
        T s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    T sum_between(int i, int j){
        return sum(j) - sum(i-1);
    }

    void plus(int i, T x){
        while(i < n){
            dat[i] += x;
            i |= i+1;
        }
    }

    // a[0]+...+a[ret] >= x
    int lower_bound(T x){
        if(x < 0) return -1;
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && dat[ret+k] < x){
                x -= dat[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    BIT<int64_t> bit(N);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        bit.plus(i, a);
    }
    while(Q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 0){
            bit.plus(a, b);
        }else{
            cout << bit.sum_between(a, b-1) << endl;
        }
    }
    return 0;
}
