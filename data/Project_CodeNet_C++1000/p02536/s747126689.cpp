// AtCoder Beginner Contest 177 (D - Friends) を 参照.
// https://atcoder.jp/contests/abc177/tasks/abc177_d
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
int connection[101010]; // 連結成分番号を保存.

// グラフを幅優先探索する.
// https://ja.wikipedia.org/wiki/幅優先探索
// ※bfsの動作確認用.
// @param G: グラフ.
// @param s: グラフの探索開始頂点.
// @param l: 連結成分番号(※1以上).
// @return: 特に無し.
void bfs(vvi &G, int s, int l){
    // 1. 空のキュー.
    queue<int> q;
    
    // 2. 連結成分番号を設定.
    connection[s] = l;
    
    // 3. 探索地点 s をキュー q に追加.
    q.push(s);
    while(!q.empty()){
        // 4. キューから取り出す.
        int u = q.front();
        q.pop();
        
        // 5. 取り出した要素を処理.
        for(auto &e : G[u]){
            // 6. 訪問済であれば, 処理をスキップ.
            if(connection[e])            continue;
            if(!connection[e] && e != s) connection[e] = l, q.push(e);
        }
    }
    return;
}

int main(){
    
    // 1. 入力情報.
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    vvi G(N);
    rep(i, M){
        scanf("%d %d", &a, &b);
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    // 2. 探索を行い, 連結成分に分割.
    int idx = 0;
    rep(i, N) if(!connection[i]) bfs(G, i, ++idx);
    
    // 3. 出力.
    printf("%d\n", idx - 1);
    return 0;
    
}