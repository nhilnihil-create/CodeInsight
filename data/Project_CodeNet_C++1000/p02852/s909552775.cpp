#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<typename Monoid,typename F>
class SegmentTree{
private:
    int sz;
    vector<Monoid> seg;
    const F op;
    const Monoid e;
public:
    SegmentTree(int n,const F op,const Monoid &e):op(op),e(e){
        sz = 1;
        while(sz<=n) sz <<= 1;
        seg.assign(2*sz,e);
    }
    void set(int k, const Monoid &x){
        seg[k+sz] = x;
    }
    void build(){
        for(int i=sz-1;i>0;i--){
            seg[i] = op(seg[2*i],seg[2*i+1]);
        }
    }
    void update(int k,const Monoid &x){
        k += sz;
        seg[k] = x;
        while(k>>=1){
            seg[k] = op(seg[2*k],seg[2*k+1]);
        }
    }
    Monoid query(int l,int r){
        Monoid L = e,R = e;
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
            if(l&1) L = op(L,seg[l++]);
            if(r&1) R = op(seg[--r],R);
        }
        return op(L,R);
    }
    Monoid operator[](const int &k)const{
        return seg[k+sz];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    auto op = [](int a,int b){return min(a,b);};
    int inf = 1e9;
    SegmentTree<int,decltype(op)> seg(N,op,inf);
    for(int i=0;i<=N;i++) if(S[i]=='0') seg.set(i,i);
    seg.build();
    vec<int> ans;
    int now = N;
    while(now){
        int ne = seg.query(max(now-M,0),now);
        if(ne==inf){
            cout << -1 << "\n";
            return 0;
        }
        ans.push_back(now-ne);
        now = ne;
    }
    reverse(ans.begin(),ans.end());
    int n = ans.size();
    for(int i=0;i<n;i++) cout << ans[i] << (i!=n-1? " ":"\n");
}