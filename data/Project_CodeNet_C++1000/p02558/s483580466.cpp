//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//省略
using vi  = vector<int>;
using vii = vector<vector<int>>;
using vl  = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// UnionFind
struct UnionFind {
    vector< int > data;
    
    UnionFind(int sz) {
        data.assign(sz, -1);
    }
 
    bool unite(int x, int y) {//要素xとyの各々の木を併合（もともと同じ木ならfalse）
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    
    int find(int k) {//要素kが属する木の根を得る
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }
    
    int size(int k) {//要素kが属する木の要素数
        return (-data[find(k)]);
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }

};

int main(){
    int N,Q;
    cin>>N>>Q;
    UnionFind tree(N);
    REP(i,Q){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==0){
            tree.unite(u,v);
        }else{
            if(tree.same(u,v)){
                cout<<"1"<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
    }
}