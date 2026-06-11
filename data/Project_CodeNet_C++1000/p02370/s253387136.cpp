// トポロジカルソート : 深さ優先探索
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<list>

using namespace std;

const int MAX = 10000;

// 各辺のつながりを格納する動的配列
vector<int> G[MAX];
// 訪問情報を保持する配列
bool V[MAX];
// トポロジカルソートの結果を格納するリスト
list<int> out;

int N;

void dfs(int u);

int main(void)
{

    int s, t, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        // 配列の初期化
        V[i] = false;
    }

    for(int i = 0; i < M; i++)
    {
        cin >> s >> t;

        // 各辺のつながりを記憶する
        G[s].push_back(t);
    }

    for(int i = 0; i < N; i++)
    {
        if( !V[i] )
        {
            // 頂点を順番に訪れる
            dfs(i);
        }
    }

    // 結果の表示
    // トポロジカルソートの結果の表示
    for(list<int>::iterator it = out.begin(); it != out.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}

// トポロジカルソートを実施するためのメソッド
// u : 訪問する頂点
void dfs(int u)
{
    // 訪問情報を記録
    V[u] = true;

    for(unsigned int i = 0; i < G[u].size(); i++ )
    {
        // 接続先の頂点No.の格納
        int v = G[u][i];

        if( !V[v] )
        {
            // 接続している頂点を順番に訪れる
            dfs(v);
        }
    }

    // 入力辺が無くなった頂点をトポロジカルキューに追加する
    out.push_front(u);

}

