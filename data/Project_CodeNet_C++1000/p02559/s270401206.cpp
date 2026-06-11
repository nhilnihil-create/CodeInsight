#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree{
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n):n(n),dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){ //[0,i]
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<n) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<=n&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
};

// https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B

void DSL_2_B(){
    int n,q; cin >> n >> q;
    BinaryIndexedTree<int> BIT(n+1);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) BIT.add(x,y);
        else cout << BIT.query(x,y+1) << '\n';
    }
}

// https://atcoder.jp/contests/practice2/tasks/practice2_b
void practice2_b(){
    int N,Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];
    BinaryIndexedTree<long long> BIT(N);
    for (int i=0;i<N;++i) BIT.add0(i,a[i]);

    for (;Q--;){
        int t; cin >> t;
        if (!t){
            int p,x; cin >> p >> x;
            BIT.add0(p,x);
        } else {
            int l,r; cin >> l >> r;
            cout << BIT.query0(l,r) << '\n';
        }
    }
}

// https://atcoder.jp/contests/arc033/tasks/arc033_3

void ARC033_C(){
    int Q; cin >> Q;
    BinaryIndexedTree<int> BIT(200010);
    for (;Q--;){
        int T,X; cin >> T >> X;
        if (T==1) BIT.add(X,1);
        else {
            int pos=BIT.lower_bound(X);
            cout << pos << '\n';
            BIT.add(pos,-1);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    practice2_b();
}