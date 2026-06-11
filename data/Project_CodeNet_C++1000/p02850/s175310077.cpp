#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int,int>>>;

int main(){
    int n;
    cin >> n;
    Graph G(n);
    REP(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(make_pair(b,i));
        G[b].push_back(make_pair(a,i));
    }
    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<pair<int,int>> que;
    int answer[n-1];

    dist[0] = 0;
    
    int max_ad = 0;

    REP(i,n){
        max_ad = max(max_ad,(int)G[i].size());
    }
    que.push(make_pair(0,-1)); // 0 を橙色頂点にする
    // BFS 開始 (キューが空になるまで探索を行う)
    int color = max_ad-1;
    while (!que.empty()) {
        pair<int,int> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        // v から辿れる頂点をすべて調べる
        for (pair<int,int> nv : G[v.first]) {
            if (dist[nv.first] != -1) {
                continue; // すでに発見済みの頂点は探索しない
            }

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv.first] = dist[v.first] + 1;

            // 色の更新
            color = (color+1)%max_ad;
            if(v.second == color){
                color = (color+1)%max_ad;
                //cout << "a" << endl;
            }
            // 答えの格納

            answer[nv.second]=color;
            que.push(make_pair(nv.first,color));
        }
    }

    cout << max_ad << endl;

    REP(i,n-1){
        cout << answer[i]+1 << endl;
    }


    return 0;
}