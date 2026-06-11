#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int UB = (N-1)*(N-2)/2;
	if (K > UB){
		cout << -1 << endl;
		return 0;
	}

	// 初期グラフを作成
	int M = N - 1;
	vector<vector<int>> graph(N, vector <int> ());
	for (int ii = 0; ii < N - 1; ++ii){
		graph[ii].push_back(N - 1);	//頂点(N-1)をハブにする
	}

	//目標に到達するまで辺を追加していく
	int now = UB;
	int v1 = 0;
	int v2 = 1;
	while (now > K) {
		graph[v1].push_back(v2);
		//v2が最後までいったらv1, v2を更新
		if (v2 == N - 2){
			v1++;
			v2 = v1 + 1;
		} else {
			v2++;
		}
		now--;
		M++;
	}


	// 結果を出力
	cout << M << "\n";
	for (int ii = 0; ii < N; ++ii){
		for (int jj = 0; jj < graph[ii].size(); ++jj){
			cout << ii + 1 << " " << graph[ii][jj] + 1 << "\n";
		}
	}

	return 0;
}
