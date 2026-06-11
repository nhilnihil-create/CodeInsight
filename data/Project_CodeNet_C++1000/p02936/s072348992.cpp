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

using Graph=vector<vector<int>>;

const int N_MAX=200100;
Graph G(N_MAX);


int main(){
    int N,Q;
    cin>>N>>Q;
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> table(N_MAX,0);
    REP(i,Q){
        int p,x;
        cin>>p>>x;
        p--;
        table[p]+=x;
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;
    
    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = table[0];
    que.push(0); // 0 を橙色頂点にする
    
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v=que.front();
        que.pop();
    
        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + table[nv];
            que.push(nv);
        }
    }
    REP(i,N){
        cout<<dist[i];
        if(i!=N-1){
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
    

    

    
}