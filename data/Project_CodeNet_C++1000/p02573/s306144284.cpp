/*
    Author:zeke

    pass System Test!
    GET AC!!
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
// cout << "Case #" << index << " :IMPOSSIBLE";
struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> tree_size;
    UnionFind(int N) : par(N),tree_size(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++){
            par[i] = i;
            tree_size[i] = 1;  //集合ごとのサイズは1と初期化しておきます
        }
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        tree_size[ry]+=tree_size[rx];
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int tree_size_info(int x){//xの属する集合のサイズを返す
        return tree_size[root(x)];
    }
};
/*
実装例
int main(){
    UnionFind tree(V);
    //UnionFind 構造体のインスタンス化　まず最初にこれを書いてください　Vは頂点数を入れてください(頂点数初期化)
    tree.unite(x,y);//xとyの頂点をつなげる
    tree.same(x,y);//xとyが同じグループに存在するかどうか
    tree.root(x);//xの根を返す
    tree.tree_size_info(x);//xの属するグループのサイズを返す
}
*/
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    ll n,m;
    cin>>n>>m;
    UnionFind tree(n);
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        tree.unite(a,b);
    }
    ll Max=0;
    rep(i,n){
        chmax(Max,(ll)tree.tree_size_info(i));
    }
    cout<<Max<<endl;
}
