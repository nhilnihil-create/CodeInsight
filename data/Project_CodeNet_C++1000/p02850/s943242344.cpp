#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N_MAX = 1e+5;

//グローバルに持っていく
// グローバルに持っていく
using Graph = vector<vector<int>>;


int main(){
    int N;
    cin >> N;
    vector<int> a(N-1),b(N-1);
    vector<int> color(N),parent(N);
    Graph G(N);
    for(int i=0;i<N-1;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    parent[0]=0;
    color[0]=0;
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    int ans=0;
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        int cnt=1;
        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
            if(cnt==color[v]) cnt++;
            parent[nv]=v;
            color[nv]=cnt;
            ans=max(ans,cnt);
            cnt++;
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }



    int tmp1,tmp2;
    cout<<ans<<endl;
    for(int i=0;i<N-1;i++){
        tmp1=a[i];
        tmp2=b[i];
        if(parent[tmp1]==tmp2){
            cout<<color[tmp1]<<endl;
        }else{
            cout<<color[tmp2]<<endl;
        }
    }
}