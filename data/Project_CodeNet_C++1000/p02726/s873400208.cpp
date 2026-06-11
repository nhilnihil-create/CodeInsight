#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, x, y;

    cin >> num >> x >> y;
    x--;
    y--;

    // マスの状況を入れる配列
    vector<vector<int>> d(num, vector<int>(num, -1));

    // 1辺ずつ調べる
    for (int i = 0; i < num; i++) {
        // キュー
        queue<int> q;
        q.push(i);
        // 自分自身を0
        d.at(i).at(i) = 0;

        while (!q.empty()) {
            // キューの先頭の要素取り出し
            auto j = q.front();
            q.pop();  // ※先頭の要素削除

            vector<int> vec2;
            if (j > 0) vec2.push_back(j - 1);
            if (j < num - 1) vec2.push_back(j + 1);
            if (j == x) vec2.push_back(y);
            if (j == y) vec2.push_back(x);

            for (auto k : vec2) {
                if (d.at(i).at(k) == -1) {
                    d.at(i).at(k) = d.at(i).at(j) + 1;
                    q.push(k);
                }
            }
        }
    }

    vector<int> vecCnt(num, 0);
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            //
            vecCnt.at(d.at(i).at(j))++;
        }
    }

    for (int i = 1; i < num; i++) cout << vecCnt.at(i) << endl;
    //
}
