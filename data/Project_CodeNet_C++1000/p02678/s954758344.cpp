#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <map> // pair

using namespace std;
using Graph = vector<vector<int32_t>>;

int main(){
    int64_t N,M;


    typedef std::pair<int64_t, int64_t> mypair;
    // first value, second weight
    vector<mypair> pairvect;

    cin >> N >> M;

    Graph G(N+1);

    for(int i=0;i<M;++i){
        int32_t A,B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> dist(N+1,-1);
    queue<int> que;

    dist[0]=0;
    dist[1]=0;
    que.push(1);

    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();// 先頭頂点をqueから削除

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {// 範囲for文
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            //dist[nv] = dist[v] + 1;
            // 今回は部屋番号を追加
            dist[nv] = v;
            que.push(nv);
        }
    }

    int flag =1;
    for(int i=2;i<=N;++i){
        if(dist[i] <0){
            flag =0;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        for(int i=2;i<=N;++i){
            cout<< dist[i]<<endl;
        }
    }
    else{
        cout<<"No"<<endl;
    }

}

