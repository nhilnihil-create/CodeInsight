// Ref : https://book.mynavi.jp/ec/products/detail/id=35408

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int main() {
	// 入力データからグラフを構築する //
	int NV, NE;
	cin >> NV >> NE;
	vector<int> inDeg(NV, 0); // 0>=:入力数, -1:探索キューに追加済み
	vector<vector<int> > graph(NV);
	for (int i = 0; i < NE; i++) {
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
		inDeg[t]++;
	}

	// トポロジカルソートを実行する //
	list<int> ans;
	// 幅優先探索でグラフを探索する
	queue<int> q;
	// 探索用キューに始点を設定
	for (int i = 0; i < NV; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
			inDeg[i] = -1;
		}
	}
	// 幅優先探索を実行する
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ans.push_back(u);
		// 隣接リストを探索し、前処理が0になったら探索キュー追加
		for (unsigned int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (inDeg[v] < 1) continue;
			if (--inDeg[v] == 0) {
				q.push(v);
				inDeg[v] = -1;
			}
		}
	}

	// グラフの頂点を, トポロジカルソートで表示する //
	for (list<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
