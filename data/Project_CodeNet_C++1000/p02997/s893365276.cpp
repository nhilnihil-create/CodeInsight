// 辺が(N-1)本とき、隣り合う(N-1)組の頂点対の最短距離は1となり、
// 頂点対(i,j)の内、最短距離が2,3,4,...となるのは
// N*(N-1)/2 - (N-1) = (N-1)(N-2)/2組である
// (N-1)(N-2)/2 < Kのとき、最短距離が2となる頂点対をK個作ることは不可能
// (N-1)(N-2)/2 >= Kのとき、頂点1とそれ以外の頂点を結ぶ(N-1)本の辺だけが
// 存在するグラフを作る（「スター」、「うに」と呼ぶ）
// このとき、頂点1以外の頂点対の最短距離は全て2であり、その数は(N-1)(N-2)/2組
// 頂点1以外の頂点対(i,j)を結ぶ辺を加えると、その頂点対だけ最短距離が1となり、
// 最短距離が2の頂点対を1つ減らせる。
// この操作で調整して、条件を満たすグラフを構築
#include <bits/stdc++.h>
using namespace std;

int graph[110][110];

int main() {
    int N, K;
    cin >> N >> K;
    if ((N - 1) * (N - 2) / 2 < K) {
        cout << -1 << endl;
        return 0;
    }
    /*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            graph[i][j] = 100000000;
        }
    }
    for (int i = 0; i < N; ++i) {
        graph[i][i] = 0;
    }
    */
    cout << (N - 1) + (N - 1) * (N - 2) / 2 - K << endl;
    
    for (int i = 2; i <= N; ++i) {
        cout << 1 << " " << i << endl;
        //graph[0][i - 1] = graph[i - 1][0] = 1;
    }
    
    int p = (N - 1) * (N - 2) / 2 - K;
    int u = 2, v = 3;
    while (p--) {
        cout << u << " " << v << endl;
        //graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
        ++v;
        if (v > N) {
            ++u;
            v = u + 1;
        }
    }
    // デバッグ
    /*
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] == 2) ++cnt;
        }
    }
    if (cnt / 2 == K)
        cout << "validate" << endl;
    else
        cout << "wrong" << endl;
    */
    return 0;
}