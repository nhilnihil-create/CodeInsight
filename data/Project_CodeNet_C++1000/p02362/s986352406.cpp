//qiita.com/wakimiko/items/69b86627bea0e8fe29d5
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_V 1000
#define INF 100000000

struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};

int main()
{
    int V; //頂点の数
    int side; //辺の数
    int S; //始点
    int G; //終点
    int d[MAX_V]; //始点からそこまで行くのにかかるコスト
    vector<edge> edges; //移動の情報を保存する

    cin >> V;
    cin >> side;
    cin >> S;

    fill(d, d+V, INF); //すべての頂点をINFにする
    d[S] = 0; //始点を0にする

    for (int i = 0; i < side; i++) {
        struct edge add;
        cin >> add.from;
        cin >> add.to;
        cin >> add.cost;
        edges.push_back(add);
    }

    bool negative_cycle=0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (int)edges.size(); j++) {

            struct edge e = edges[j];

            if ((d[e.to] > d[e.from] + e.cost)&&(d[e.from]<INF)) {  //移動した後のコストが小さいと、頂点のコストを更新
                d[e.to] = d[e.from] + e.cost;
                if (i == V-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    negative_cycle=1;
                    break;
                } 
            }
        }
    }

    if(negative_cycle==0){
        for(int i=0; i<V; i++){
            if(d[i]<INF){
                cout << d[i] << endl;
            }else{
                cout << "INF" << endl;
            }
        }
    }else{
        cout << "NEGATIVE CYCLE" << endl;
    }
    return 0;
}

