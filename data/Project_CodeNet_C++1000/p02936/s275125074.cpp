//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

// 木のdfs 
// 木は隣接要素の親以外へ向かう有効グラフ↓
// seenの代わりに親ノードには逆走しない形にする
/////////////////////////////////////////////////////////////////////////
using Graph = vector<vector<int>>;

// vector<bool> seen;
vector<ll int> ans;

void dfs(const Graph &G, int v, int p, vector<ll int> &res) {
    
    // 最初は親がいないのでこうする
    if(p!=-1){
        res[v] += res[p];
    }
    // v から行ける各頂点 next_v について
    // 範囲for文
    for (auto next_v : G[v]) { 
        if(next_v==p) continue; // nextが親の時はダメ
        dfs(G, next_v, v, res); // 再帰的に探索
    }
}
// 累積和を使った考え方（普通にやるとO(QN)でやばい）
int main() {
    // 入力
    int N, Q; cin >> N >> Q;

    // グラフ入力受取 
    Graph G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1); // 無効グラフの場合
    }

    // 入力p,x
    vector<P> px(N);
    for(int i=0;i<Q;i++){
        cin >> px[i].first >> px[i].second;
    }

    ans.assign(N,0); //0で初期化
    for(int i=0;i<Q;i++){
        ans[px[i].first-1]+=px[i].second;
    }

    // seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, -1, ans); // 0からdfs

    // 出力
    for(int i=0; i<N;i++){
        cout << ans[i] << ' ';
    }
}

// 行きがけ順、帰りがけ順
// タイムスタンプ

// 辺に重みがある場合qiitaのpageへgo(構造体を作ってあげる)

// 豊富な例　https://qiita.com/drken/items/a803d4fc4a727e02f7ba
// ・grid探索
// ・連結成分個数
// ・二部グラフ判定
// ・木の場合のDFS(木の深さ、部分木の大きさ)