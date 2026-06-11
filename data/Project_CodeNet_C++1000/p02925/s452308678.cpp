#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int maxN = 1005;
const int maxV = maxN * (maxN - 1) / 2;
// トポロジカルソートされるグラフ
vector<int> to[maxV];
int id[maxN][maxN];
 
int toId(int i, int j) {
    if (i > j) swap(i, j);
    return id[i][j];
}
 
bool visited[maxV]; // 関数外の変数については, ポインタはnull数値はゼロ値になるらしい.
bool calced[maxV];
int day[maxV];
int dfs(int v) {
    if (visited[v]) {
        if (!calced[v]) return -1;
        return day[v];
    }
    visited[v] = true;
    day[v] = 1;
    // この計算中にまた自分自信に来ることがある. そのときは絶対に完成しないので, -1を返す.
    for (int e : to[v]) {
        int dayBefore = dfs(e); // 前回の回の日程を取得している.
        if (dayBefore == -1) {
            return -1;
        }
        // vに来るまでにやつ必要があった試合の日付よりも後の日付に設定する
        day[v] = max(day[v], dayBefore + 1);
    }
    calced[v] = true;
    return day[v];
}
 
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // A_{i, j + 1} は A_{i, j}が終わらないとできない -> Aが終わった後にBをしなければならない
    // とき A -> Bとしたグラフを作り, そのグラフについてトポロジカルソートみたいなことをやる.
    // トポロジカルソートすると同時に, day(B) = day(A) + 1みたいな感じにしておく
    int N;
    cin >> N;
 
    // 対戦相手の情報をとりあえず入れておくやつ
    vector<vector<int>> ops(N, vector<int>(N - 1));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> ops[i][j];
            ops[i][j]--;
        }
    }
    // 次はidを振る
    int V = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) continue;
            id[i][j] = V++;
        }
    }
    // そして試合番号のグラフを作る
    // 次のやつをグラフに入れるだけでいい.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            // 一つ後の試合番号 ひとつ前の試合番号
            to[toId(i, ops[i][j + 1])].push_back(toId(i, ops[i][j]));
        }
    }
    // 次はトポロジカルソートっぽいことをして, 何日目かを得る.
    int last = 0;
    for (int v = 0; v < V; v++) {
        int day = dfs(v);
        if (day == -1) {
            cout << -1 << endl;
            return 0;
        }
        last = max(last ,day);
    }
    cout << last << endl;
 
    return 0;
}