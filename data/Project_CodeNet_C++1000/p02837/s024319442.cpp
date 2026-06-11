#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    //i番目の人が、j番目の人に対して証言した内容を保存する2次元配列
    int graph[15][15];
    int N;
    cin >> N;
    //2次元配列の初期化（j番目の人が正しいことをいう人とも、審議不明のことをいう人とも設定していない状態）
    rep(i, N) rep(j, N) graph[i][j] = -1;
    //2次元配列への書き込み部分
    rep(i, N){
        int m;
        cin >> m;
        rep(j, m){
            int x, y;
            cin >> x >> y;
            x--;
            graph[i][x] = y;
        }
    }
    //正しいことをいう人の最大値を格納
    int ans = 0;
    //変数bitに格納されているビット全探索の状態を、配列dに書き換えている
    rep(bit, 1<<N){
        vector<int> d(N);
        rep(j, N) if((bit>>j)&1) d[j] = 1;

        bool is = true;
        rep(i, N){
            //i番目の人が、bit全探索の状態で、正しいことを言う人であると設定されているなら行う
            if(d[i]){
                //i番目の人から見て、j番目の人が、審議不明の発言をする人でないかどうかチェック
                rep(j, N){
                    if(graph[i][j] == -1) continue;
                    //d[j]には、j番目の人が正しい発言をする人であるかどうかが格納されているので、
                    //正しい発言をする人であるi番目の人の証言と、d[j]が異なっていれば、矛盾発生となる。
                    if(graph[i][j] != d[j]) is = false;
                }
            }
        }
        if(is) ans = max(ans, __builtin_popcount(bit));
    }
    cout << ans << endl;
    return 0;
}