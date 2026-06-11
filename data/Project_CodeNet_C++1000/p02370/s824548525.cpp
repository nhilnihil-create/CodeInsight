// トポロジカルソート
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>

#include<queue>

using namespace std;

const int MAX_V = 10000;
const int MAX_E = 100000;

const int NO = 0;
const int MID = 1;
const int YES = 2;

// 各辺のつながりを格納する動的配列
vector<int> v_connection[MAX_V];
// 訪問情報を保持する配列
int ary_visit[MAX_V];
// 入力辺の数を格納する配列
int ary_inputEdge[MAX_V];
// トポロジカルソートの結果を格納するキュー
queue<int> topo_que;

void TopologicalSort(int v);

int main(void)
{

    int n, edge;
    int first, second;

    cin >> n >> edge;

    for(int i = 0; i < n; i++)
    {
        // 配列の初期化
        ary_inputEdge[i] = 0;
        ary_visit[i] = NO;
    }

    for(int i = 0; i < edge; i++)
    {
        cin >> first >> second;

        // 入力辺の数を記憶する
        ary_inputEdge[second]++;
        // 各辺のつながりを記憶する
        v_connection[first].push_back(second);
    }

    for(int i = 0; i < n; i++)
    {
        if( ary_visit[i] == NO )
        {
            // 頂点を順番に訪れる
            TopologicalSort(i);
        }
    }

    // 結果の表示
    int size = topo_que.size();

    int *result = new int[size];

    for(int i = size - 1; i >= 0; i--)
    {
        int val = topo_que.front();
        topo_que.pop();

        result[i] = val;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

// トポロジカルソートを実施するためのメソッド
// v : 訪問する頂点
void TopologicalSort(int v)
{
    int connect_v;

    if( ary_inputEdge[v] >= 0 && ary_visit[v] == NO )
    {
        // 訪問途中を記録
        ary_visit[v] = MID;

        for(unsigned int i = 0; i < v_connection[v].size(); i++ )
        {
            // 接続先の頂点No.の格納
            connect_v = v_connection[v][i];

            // vから接続している頂点の入力辺の次数を減算する
            ary_inputEdge[connect_v]--;
            // 接続している頂点を順番に訪れる
            TopologicalSort(connect_v);
        }
    }

    //if( ary_inputEdge[v] == 0 )
    if( ary_visit[v] == MID )
    {
        // 入力辺が無くなった頂点をトポロジカルキューに追加する
        topo_que.push(v);
        ary_inputEdge[v]--;
        ary_visit[v] = YES;
    }

}

