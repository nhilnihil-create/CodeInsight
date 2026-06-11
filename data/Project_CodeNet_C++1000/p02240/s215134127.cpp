#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz;

    UnionFind(int N) : par(N), siz(N, 1LL) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
//重み付きUF
struct UnionFind_w {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> diff_weight;
    UnionFind_w(int n){ //最初は全てが根であるとして初期化
        init(n);
    }
    void init(int n) {
        par.resize(n);
        diff_weight.resize(n);
        REP(i,n){
            par[i] = i;
            diff_weight[i] = 0;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    int weight(int x){
        root(x);
        return diff_weight[x];
    }

    void unite(int x, int y,int w) { // xとyの木を併合
        w -= weight(x);
        w += weight(y);
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        diff_weight[rx] = w;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int diff(int x,int y){
        return weight(x) - weight(y);
    }
};


signed main(){
    cin >> n;
    UnionFind uf(n);
    int m;
    cin >> m;
    REP(i,m){
        int s,t;
        cin >> s >> t;
        uf.unite(s,t);
    }
    int q;
    cin >> q;
    REP(i,q){
        int s,t;
        cin >> s >> t;
        if(uf.same(s,t)){
            print("yes");
        }
        else{
            print("no");
        }
    }


    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}

//key以上の初めてのitr
int nibul(auto a,auto b){return lower_bound(All(a),b) - a.begin();}
//key以下の最後のitr
int nibuu(auto a,auto b){return upper_bound(All(a),b) - a.begin()-1;}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

