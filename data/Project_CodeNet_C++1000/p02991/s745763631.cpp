//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数

//ライブラリ挿入


int main(){
    int N,M,s,t;
    cin >> N >> M;
    
    // グラフ入力受取 
    vector<vector<int>> G(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }
    cin >> s >> t;
    s--;
    t--;

    // BFS のためのデータ構造
    vector<vector<int>> dist(N,vector<int>(3,-1)); // 全頂点を「未訪問」に初期化
    queue<pair<int,int>> que;
    
    // 初期条件 
    dist[s][0] = 0;
    que.push(make_pair(s,0)); // 0 を橙色頂点にする
    
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<int,int> q=que.front();
        que.front(); // キューから先頭頂点を取り出す
        que.pop();
        int v=q.first;
        int n=q.second;
    
        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv][(n+1)%3] != -1) continue; // すでに発見済みの頂点は探索しない
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv][(n+1)%3] = dist[v][n] + 1;
            que.push(make_pair(nv,(n+1)%3));
        }
    }

    if(dist[t][0]!=-1) dist[t][0]/=3;
    cout<<dist[t][0]<<endl;

}