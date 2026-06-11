// 問題名: Edit Distance
// URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
// 所要時間: 40分(カンニングあり)
// --感想--
// 編集距離が出てくる問題は何度か解いたことがあったが、編集距離そのものを求める問題を解いたことがなかったため、
// 典型問題に触れることができて良い勉強になった。考察は考えても浮かばなかったため、
// https://qiita.com/odenmonster/items/db443d5808788a869fe9
// こちらのサイトを参考にした。

#include <bits/stdc++.h>
using namespace std;

int n;
void dfs(int level, pair<double, double> pl, pair<double, double> pr){
    if(level < n){
        pair<double, double> p1, p2, p3; // 新しくできる頂点
        p1 = make_pair((pl.first * 2 + pr.first) / 3, (pl.second * 2 + pr.second) / 3);
        p3 = make_pair((pl.first + pr.first * 2) / 3, (pl.second + pr.second * 2) / 3);
        pair<double, double> v = make_pair(p3.first-p1.first, p3.second-p1.second); // p3-p1
        double a = v.first, b = v.second, r3 = sqrt(3);
        v = make_pair(a / 2 - b * r3 / 2, a * r3 / 2 + b / 2); // vを反時計回りに60度回転
        p2 = make_pair(p1.first + v.first, p1.second + v.second);
        dfs(level + 1, pl, p1);
        dfs(level + 1, p1, p2);
        dfs(level + 1, p2, p3);
        dfs(level + 1, p3, pr);
    }
    else
        cout << pl.first << " " << pl.second << endl;
    if(level == 0)
        cout << pr.first << " " << pr.second << endl;
}

int main(){
    cin >> n;
    dfs(0, make_pair(0.0, 0.0), make_pair(100.0, 0.0));
}
