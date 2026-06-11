#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int NIL = -1;
static const int MAX = 100;
static const int INFTY = 10000000;


int colors[MAX] = { WHITE };	//各頂点の訪問状態
int graph[MAX][MAX] = { INFTY };
int d[MAX] = { INFTY };		//原点からの各頂点の距離
int p[MAX] = { NIL };		//親頂点

void dijkstra(int n) {

    d[0] = 0;
    colors[0] = WHITE;

    while (true) {

	int mincost = INFTY;
	int u;

	for (int i = 0; i < n; i++) {
	    //まだコストが確定しておらず、かつ現時点で仮コストが出ているもの
	    if (colors[i] != BLACK&&d[i] != INFTY) {

		//より小さいコストの原点からの距離があったら
		if (d[i] < mincost) {
		    mincost = d[i];
		    u = i;
		}
	    }
	}

	if (mincost == INFTY) {
	    break;
	}

	colors[u] = BLACK;

	//確定した頂点uからの近隣探索
	for (int i = 0; i < n; i++) {
	    
	    //まだ確定しておらずvから辺があれば
	    if (colors[i] != BLACK&&graph[u][i] != INFTY) {


		//現時点でiに行くコストより
		//頂点uを経由した方がコストが小さかったら
		if (d[u]+graph[u][i] < d[i]) {
		    d[i] = d[u] + graph[u][i];
		    p[i] = u;
		}

	    }

	}

    }
}

int main() {

    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    int n; scanf("%d", &n);
    int u; //頂点
    int k; //vからの辺の数
    int v; //uにつながる頂点v
    int c; //コスト

    //グラフ初期化
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    graph[i][j] = INFTY;
	}
    }
    
    //距離d初期化
    for(int i = 0; i < n; i++) {
	d[i] = INFTY;
    }

    //グラフ読み込み
    for (int i = 0; i < n; i++) {
	scanf("%d", &u);
	scanf("%d", &k);
	for (int j = 0; j < k; j++) {
	    scanf("%d", &v);
	    scanf("%d", &c);
	    graph[u][v] = c;
	}
    }


    //ダイクストラ法
    dijkstra(n);

    //表示
    for (int i = 0; i < n; i++) {
	printf("%d %d\n", i, d[i]);
    }

    return 0;

}


