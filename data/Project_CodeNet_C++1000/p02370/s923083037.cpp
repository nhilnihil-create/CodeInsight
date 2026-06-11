#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

const int MAX_V = 10000;
const int MAX_E = 100000;
vector<deque<int> > G(MAX_E);
vector<int> L;  // トポロジカルソートした結果を蓄積する空リスト.
deque<int> S;   // 入力辺を持たないすべてのノードの集合.
map<int, int> inCount;

// 各頂点から, トポロジカルソート を行い, 頂点の並び順を保存.
void topologicalSort(){
    
    // 1. キュー S が 空になるまで, ループ.
    while(!S.empty()){

        // 2. S からノード n を削除.
        int n = S.front();
        S.pop_front();
        
        // 3. L に n を追加.
        L.push_back(n);

        while(!G[n].empty()){
            // 4. 辺 e (n -> m)をグラフから削除.
            int m = G[n].front();
            G[n].pop_front();
            inCount[m]--;
            // printf("n=%d m=%d\n", n, m);
            // 5. m がその他の入力辺を持っていなければ, m を S に追加.
            if(inCount[m] == 0) S.push_back(m);
        }
    }
    
    // 6. グラフに辺が残っている場合は, 閉路があり DAG でないので中断.
    // 本問では, 考慮しなくて良さそう.
    
    return;
}

int main(){
    
    // 1. 入力情報.
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        inCount[t]++; // 各頂点への入力辺の本数を保存.
    }
    
    // 2. 辺の数が, 0本の場合, 頂点を S に追加.
    // -> 入力情報に, 必ずしも, 頂点情報が与えらるとは, 限らないので注意.
    for(int i = 0; i < V; i++) if(inCount[i] == 0) S.push_back(i);
    
    // 3. トポロジカルソートを行う.
    topologicalSort();
    
    // 4. 出力 ～ 後処理.
    for(int i = 0; i < L.size(); i++) printf("%d\n", L[i]);
    return 0;

}

