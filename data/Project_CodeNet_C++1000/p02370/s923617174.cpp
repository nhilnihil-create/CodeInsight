#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <list>

using namespace std;

static const int MAX = 10000;
static const int WHITE = 0;
static const int BLACK  =2;

vector<int> G[MAX];                     //隣接リスト G[i]にはi番目の頂点から向かう頂点が格納されている
int colors[MAX] = {WHITE};              //色
int inDegrees[MAX] = {0};               //入次数
list<int> orders;                        //頂点の順番格納

void bfs(int v);

//トポロジカルソート
void topologicalSort(int vNumber){

    //色と入次数の初期化
    for(int i=0;i<vNumber;i++){
        colors[i] = WHITE;
        inDegrees[i] = 0;
    }

    //inDegreeをそれぞれ格納
    for(int i=0;i<vNumber;i++){
        for(int j=0;j<G[i].size();j++){
            int v = G[i][j];
            inDegrees[v]++;
        }
    }


    //各頂点から行う
    for(int i=0;i<vNumber;i++){

        //すでに順番が決まっていない
        //かつ、入次数がゼロの場合
        if(colors[i] != BLACK  &&  inDegrees[i]  == 0){
            bfs(i);
        }
    }

}

//幅優先探索
void bfs(int v){

    //順番確定
    colors[v] = BLACK;

    //頂点vを含む集合の更新
    queue<int> Q;
    Q.push(v);

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        orders.push_back(u);


        for(int i=0;i<G[u].size();i++){
            //辺の削除
            int to = G[u][i];
            inDegrees[to]--;

            //uからの向かう頂点が浮いていた場合
            if(inDegrees[to] == 0 && colors[to] !=BLACK){
                colors[to] = BLACK;
                Q.push(to);
            }
        }
    }

}

void print(){
    for(auto it=orders.begin(); it!= orders.end();it++){
        printf("%d\n",*it);
    }
}

int main() {

    int V; scanf("%d", &V);
    int E; scanf("%d", &E);

    int s, t;
    for(int i=0;i<E;i++){
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }

    topologicalSort(V);

    print();

    return 0;
}
