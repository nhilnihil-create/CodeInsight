#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

template<class T>
struct segment_tree {
    using F = function<T(T,T)>;
    int n;
    vector<T> data;
    F f;
    T init_v;

    segment_tree(int n_, T init_v, F f) : f(f), init_v(init_v) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1,init_v);
    }

    //kをaに変更
    void update(int k, T a) {
        k += n-1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = f(data[k*2+1],data[k*2+2]);
        }
    }

    //[a,b)のquery,kは節点番号
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return data[k];
        else {
            T vl = query(a,b,k*2+1,l,(l+r)/2);
            T vr = query(a,b,2*k+2,(l+r)/2,r);
            return f(vl,vr);
        }
    }

    T operator[](int a) {return data[a+n-1];}

    //[a,b)を出力
    void debug_seg(int a, int b) {
        a += n-1; b += n-1;
        for (int i = a; i < b; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    auto f = [](P a, P b) {
        if (a.first <= b.first) return a;
        else return b;
    };
    segment_tree<P> sg(n+1,P(inf,-1),f);
    sg.update(0,P(0,0));
    vint pre(n+1,-1);
    REP(i,n+1) {
        // sg.debug_seg(0,n+1);
        if (s[i] == '1') continue;
        P p = sg.query(max(0,i-m),i);
        pre[i] = p.second;
        sg.update(i,P(p.first+1,i));
    }
    vint path;
    for (int i = n; pre[i] != -1; i = pre[i]) {
        path.push_back(i);
    }
    path.push_back(0);
    reverse(all(path));
    if (path.size() == 1) cout << -1 << endl;
    else {
        rep(i,path.size()-1) cout << path[i+1] - path[i] << endl;
    }
}