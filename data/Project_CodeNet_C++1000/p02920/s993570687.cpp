#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

template<typename Monoid> struct Lazy_Segment_Tree{
    //二項演算
    Monoid ope(Monoid a, Monoid b) {return a+b;}
    //単位元
    Monoid unit;
    int n;
    vector<Monoid> seg, lazy;
    //要素数N(0-indexed)のxを単位元とする遅延セグメント木を構築
    Lazy_Segment_Tree(int N, Monoid x){
        unit = x;
        n = 1;
        while(n < N) n <<= 1;
        seg.assign(2*n, unit);
        lazy.assign(2*n, unit);
    }
    //i番目のノードについて、遅延評価(遅延配列の伝搬)をする
    void eval(int i, int l, int r){
        if(lazy[i] != unit){
            seg[i] = ope(seg[i], lazy[i]);
            if(r-l > 1){
                lazy[2*i] = ope(lazy[2*i] ,lazy[i]/2);//可変
                lazy[2*i+1] = ope(lazy[2*i+1], lazy[i]/2);
            }
            lazy[i] = unit;
        }
    }
    //change(a, b, x)で[a,b)にxを演算する
    void change(int a, int b, Monoid x, int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        eval(i, l, r);
        if(a >= r || b <= l) return;
        elif(a <= l && r <= b){
            lazy[i] = ope(lazy[i], (r-l)*x);//可変
            eval(i, l, r);
        }
        else{
            change(a, b, x, 2*i, l, (l+r)/2);
            change(a, b, x, 2*i+1, (l+r)/2, r);
            seg[i] = ope(seg[2*i], seg[2*i+1]);
        }
    }
    //query(a, b)で[a, b)における演算の結果を取得
    Monoid query(int a, int b, int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(a >= r || b <= l) return unit;
        eval(i, l, r);
        if(a <= l && r <= b) return seg[i];
        else{
            Monoid vl = query(a, b, 2*i, l, (l+r)/2);
            Monoid vr = query(a, b, 2*i+1, (l+r)/2, r);
            return ope(vl, vr);
        }
    }
    //O(N)で全ての遅延配列を本配列に組み込む
    void update(int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        seg[i] = ope(seg[i], lazy[i]);
        if(r-l > 1){
            lazy[2*i] = ope(lazy[2*i] ,lazy[i]/2);//可変
            lazy[2*i+1] = ope(lazy[2*i+1], lazy[i]/2);
            update(2*i, l, (l+r)/2);
            update(2*i+1, (l+r)/2, r);
        }
        lazy[i] = unit;
    }
    //本配列のi番目の要素を取得
    Monoid at(int i){
        return seg[n+i];
    }
    //初期化する
    void clear(){
        fill(seg.begin(), seg.end(), unit);
        fill(lazy.begin(), lazy.end(), unit);
    }
};

int main(){
    int N;
    cin >> N;
    int S[1<<N];
    rep(i, 1<<N) cin >> S[i];
    sort(S, S+(1<<N), greater<int>());
    vector<int> v;
    for(int i = 0; i < (1<<N);){
        int j = 0;
        while(i+j < (1<<N) && S[i] == S[i+j]) j++;
        v.pb(j), i += j;
    }
    priority_queue<int> que;
    queue<int> memo;
    que.push(N);
    for(auto &e: v){
        if(que.size() < e) {cout << "No" << endl; return 0;}
        rep(i, e){
            memo.push(que.top());
            que.pop();
        }
        while(!memo.empty()){
            int e = memo.front();
            memo.pop();
            rep(i, e) que.push(i);
        }
    }
    cout << "Yes" << endl;
}