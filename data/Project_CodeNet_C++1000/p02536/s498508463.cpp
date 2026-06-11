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
const int inf = 1<<30;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

// union-find
struct union_find {
    vector<int> data;

    union_find(int size) {data.resize(size,-1);}

    int find(int x) {
        if (data[x] < 0) {return x;}
        return data[x] = find(data[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {return false;}
        if (data[x] > data[y]) swap(x,y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int size(int x) {return -data[find(x)];}
};

int main() {
    int n, m; cin >> n >> m;
    union_find uf(n);
    int ans = n - 1;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (uf.unite(a,b)) ans--;
    }
    cout << ans << endl;
}