// 深さ優先探索
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>

#include<stack>

using namespace std;

#define MAX_N 100
// 値の定義
const int EXIST = 1;
const int NO_EXIST = 0;

const int WHITE = 0;// 未訪問
const int GRAY = 1; // 訪問中
const int BLACK = 2;// 訪問完了

const int INV = -1;

// グラフ情報を保持する配列
int ary_graph[MAX_N + 1][MAX_N + 1];

// 各頂点の訪問状態を保持する配列
int color[MAX_N + 1];

// 発見時刻と完了時刻を保持する構造体
typedef struct
{
    int start_time;
    int end_time;
}SearchTime;

SearchTime st_SearchTime[MAX_N + 1];
int search_T = 0;

int vertex_num = 0;
int nt[MAX_N + 1];

void depthFirstSearch(int now_vertex);

int main(void)
{
    int n, u, num, v_num;

    for(int i = 0; i < MAX_N + 1; i++)
    {
        color[i] = WHITE;
        nt[i] = 0;

        for(int j = 0; j < MAX_N + 1; j++)
        {
            // 配列の初期化
            ary_graph[i][j] = NO_EXIST;
        }
    }

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> u >> num;

        // 0オリジンにする
        u--;

        for(int j = 0; j < num; j++)
        {
            // 隣接点を記憶する
            cin >> v_num;

            // 0オリジンにする
            v_num--;
            ary_graph[u][v_num] = EXIST;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if( color[i] == WHITE )
        {
            // 未訪問の点を始点として, 深さ優先探索を実施
            vertex_num = n;
            depthFirstSearch(i);
        }
    }

    // 結果の表示
    for(int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", i + 1, st_SearchTime[i].start_time, st_SearchTime[i].end_time);
    }

    return 0;
}

// u に隣接する v を番号順に取得
int next(int u)
{
    int ret = INV;

    for(int v = nt[u]; v < vertex_num; v++)
    {
        nt[u] = v + 1;

        if( ary_graph[u][v] == EXIST )
        {
            // 隣接点が存在する
            ret = v;
            break;
        }
    }

    return ret;
}

// 深さ優先探索を実施する関数
// now_vertex : 現在の頂点のNo.
void depthFirstSearch(int now_vertex)
{
    stack<int> S;

    // スタックにプッシュする
    S.push(now_vertex);
    // 訪問中を設定
    color[now_vertex] = GRAY;
    // 発見時刻の設定
    search_T++;
    st_SearchTime[now_vertex].start_time = search_T;

    while( !S.empty() )
    {
        int u = S.top();
        // uの隣接点を検索する
        int v = next(u);

        if( v != INV )
        {
            // 隣接点が訪問済みの場合は何もしない

            if( color[v] == WHITE )
            {
                // 訪問中を設定
                color[v] = GRAY;
                // 発見時刻の設定
                search_T++;
                st_SearchTime[v].start_time = search_T;
                // スタックにプッシュする
                S.push(v);
            }
        }
        else
        {
            // 隣接点が存在しない時は訪問完了なので, スタックから削除する
            S.pop();
            color[u] = BLACK;

            // 終了時刻の設定
            search_T++;
            st_SearchTime[u].end_time = search_T;
        }
    }

    return;
}

