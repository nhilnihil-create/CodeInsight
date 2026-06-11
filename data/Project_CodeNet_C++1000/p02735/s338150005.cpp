#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

//グローバル変数として、諸変数を宣言
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const ll INF = 10000000;
int H, W;
vector<string> grid;

ll solve(){
    //用いるdpのvector配列を生成。最初は非常に大きな値を入れておく
    vector<vector<ll>> dp(H, vector<ll>(W, INF));
    //左上のマスの初期状態によって、dp[0][0]の初期状態を変更
    if(grid[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    //dp開始
    rep(i, H){
        rep(j, W){
            //各マスから、右と下への移動を見る
            for(int dir = 0; dir < 2; dir++){
                int next_i = i + dx[dir], next_j = j + dy[dir];
                //next_i, next_jが、H*Wのグリッドの外に出てしまった場合は、飛ばす（次の経路を考える）
                if(next_i >= H || next_j >= W) continue;
                //(i, j)から、(next_i, next_j)に到達するまでに必要なコストをaddに入れる
                //今回の問題では、コストは、塗り替えの回数を表す
                int add = 0;
                //(i, j)が通路（白で塗られたマス）で、(next_i, next_j)が壁（黒で塗られたマス）の場合には、コストが1必要
                //コストが1必要というのは、塗り替えを1回行わなければならない
                if(grid[next_i][next_j] == '#' && grid[i][j] == '.') add = 1;
                //dp[next_i][next_j]の値を更新する。この更新は、dp[next_i][next_j] > (dp[i][j] + add)の時に行われる
                dp[next_i][next_j] = min(dp[i][j] + add, dp[next_i][next_j]);
            }
        }
    }
    return dp[H-1][W-1];
}

int main(){
    cin >> H >> W;
    //H*Wマスの状態を入力する2次元配列gridはグローバル領域で宣言しているので、
    //vector配列の要素数を指定
    grid.resize(H);
    rep(i, H) cin >> grid[i];
    cout << solve() << endl;
    return 0;
}