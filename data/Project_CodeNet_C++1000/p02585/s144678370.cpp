#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

# define MAX_N 100010 // 10^5 + 10

// UnionFindTree
// 使い方(インスタンス名 : tree)
// インスタンス生成 : UnionFind tree;
// tree.init(要素数)
// uniteしたりsameかどうか判定したり

class UnionFind{
    private:
        int par_[MAX_N];
        int rank_[MAX_N];
        int size[MAX_N];
        int groups_;
    
    public:
        void init(int n){ // initializes the tree 
            for(int i=0; i<n; i++){
                par_[i] = i;
                rank_[i] = 0;
                size[i] = 1;
            }
            groups_ = n;
        } 
        int rootOf(int x){ // returns the root of x 
            if(par_[x] == x){
                return x;
            }
            else{
                return par_[x] = rootOf(par_[x]);
            }
        } 
        void unite(int x, int y){ // unites x and y 
            x = rootOf(x);
            y = rootOf(y);
            if(x == y) return;
            if(rank_[x] < rank_[y]){
                par_[x] = y;
                groups_--;
                size[y] += size[x];
            }
            else{
                par_[y] = x;
                groups_--;
                size[x] += size[y];
                if(rank_[x] == rank_[y]) rank_[x]++;
            }
        }
        bool isSameGroupe(int x, int y){ // whether x and y are united
            return rootOf(x) == rootOf(y);
        }
        int countGroups(){ // returns the number of groups
            return groups_;
        }
        // 6 / 19 Updated!! (連結成分のサイズを返す)
        int sizeOf(int x){
            return size[rootOf(x)];
        }
};

int main(void){
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    UnionFind tree;
    tree.init(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        tree.unite(i, p[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    // scr[i][j] := i から出発して j回 移動した時のスコア
    ll scr[5050][5050];
    memset(scr, 0, sizeof(scr));

    for(int i = 0; i < n; i++){
        ll now = i;
        for(int j = 0; j <= n; j++){
            if(j-1 >= 0){
                now = p[now];
                scr[i][j] = scr[i][j-1] + c[now];
            }
            else{
                scr[i][j] = 0;
            }
        }
    }

    // ループを調べる
    vector<ll> lp(n); // lp[i] := i が含まれるループのスコアの総和
    for(int i = 0; i < n; i++){
        lp[i] += c[i];
        for(int j = 0; j < n; j++){
            if(i != j && tree.isSameGroupe(i, j)){
                lp[i] += c[j];
            }
        }
    }

    ll ans = ll(-10e11);
    for(int i = 0; i < n; i++){
        ll len = tree.sizeOf(i); // i が含まれるループの長さ

        // あまりの長さで場合分け(なんで、これで、通るの???????????)
        for(int r = 0; r < len; r++){
            if(r > k) continue;
            ll q = (k - r) / len;
            if(r == 0 && q == 0) continue;
            if(lp[i] > 0) ans = max(ans, lp[i] * q + scr[i][r]);
            else if(r > 0) ans = max(ans, scr[i][r]);
        }

    }
    cout << ans << endl;
    return 0;
}