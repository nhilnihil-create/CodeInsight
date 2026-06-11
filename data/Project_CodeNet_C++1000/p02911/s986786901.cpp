#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


template<typename T> class LazyRMQ {
    T def;                       // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理

    public:
    int n;
    vector<T> data, lazy;

    LazyRMQ(int m, T _def, function<T(T, T)> _operation)
    : operation(_operation) 
    {
        // 2のべき乗にする
        n = 1;
        while(n < m) n <<= 1;
        def=_def;
        data.assign(2*n-1, def);
        lazy.assign(2*n-1, 0);
    }

    void eval(int k, int kl, int kr){
        if(data[k] == def) data[k] = 0;
        if(lazy[k] == 0) return;
        data[k] += lazy[k];
        if(kr - kl > 1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    // [s,t)
    void add(int s, int t, T x, int k, int kl, int kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return;
        if(s <= kl && kr <= t){
            lazy[k] += x;
            eval(k, kl, kr);
            return;
        }
        int kc = (kl+kr)/2;
        add(s, t, x, 2*k+1, kl, kc);
        add(s, t, x, 2*k+2, kc, kr);
        data[k] = operation(data[2*k+1], data[2*k+2]);
    }

    // [s,t)
    void add(int s, int t, T x) {
        add(s, t, x, 0, 0, n);
    }

    // [s,t)
    T find(int s, int t, int k, int kl, int kr){ // 区間クエリー実行
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return def;
        if(s <= kl && kr <= t) return data[k];
        int kc = (kl+kr)/2;
        T vl = find(s, t, 2*k+1, kl, kc);
        T vr = find(s, t, 2*k+2, kc, kr);
        return operation(vl, vr);
    }

    T find(int s, int t) {
        return find(s, t, 0, 0, n);
    }
};

///////////////////////////// 1-indexed
// 区間クエリ                                                  dif
// 区間ｍinクエリ： [](int a, int b){ return min(a, b); }       INF
// 区間ｍaxクエリ： [](int a, int b){ return max(a, b); }      -INF
// 区間和：        [](int a, int b){ return a + b; }            0
/////////////////////////////

int main(void) {
    int N, K, Q;
    cin >> N >> K >> Q;
    LazyRMQ<int> st(N, 0,
                          [](int a, int b) { return a+b; });
    st.add(1,N+1,K);
    rep(q, Q) {
        int a;
        cin >> a;
        st.add(1  , a ,-1);
        st.add(a+1,N+1,-1);
    }
    rep(i,N){
        if(st.find(i+1,i+2)>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}