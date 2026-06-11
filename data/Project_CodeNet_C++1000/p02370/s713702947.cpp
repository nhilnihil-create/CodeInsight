#include <bits/stdc++.h>
using namespace std;
vector<int> topological_sort(vector<vector<int>> &E){
	int N = E.size();
	vector<int> deg(N, 0);
	for (int i = 0; i < N; i++){
		for (int j : E[i]){
			deg[j]++;
		}
	}
	queue<int> Q;
	for (int i = 0; i < N; i++){
		if (deg[i] == 0){
			Q.push(i);
		}
	}
	vector<int> ans;
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		ans.push_back(v);
		for (int w : E[v]){
			deg[w]--;
			if (deg[w] == 0){
				Q.push(w);
			}
		}
	}
	return ans;
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int s, t;
    cin >> s >> t;
    E[s].push_back(t);
  }
  vector<int> ans = topological_sort(E);
  for (int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }
}
