#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
struct UnionFind {
    vector<int> par;
    
    //要素nで初期化
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    //xが属する集合の根を返す
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    //xとyが同じ集合に属しているかを判定
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    //xが属する集合とyが属する集合をマージ
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // 計算量が減るよ
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    //xが属する集合のサイズ
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
	int n,m;cin>>n>>m;
	UnionFind uf(n);
	for(int i = 0; i < m; i++) {
		int a,b;cin>>a>>b;a--;b--;
		uf.merge(a,b);
	}
	set<int> res;
	for(int i = 0; i < n; i++) {
		int r = uf.root(i);
		res.insert(r);
	}
	cout << res.size() - 1 << endl;
	return 0;
}