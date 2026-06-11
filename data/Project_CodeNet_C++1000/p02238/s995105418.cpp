#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

int N;
Graph G;
vector<int> td, tf;
int timestamp;

void dfs(int v){
	td[v] = timestamp++;

	for(int i=0; i<G[v].size(); i++){
		int u = G[v][i];
		if(td[u] == -1){
			dfs(u);
		}
	}

	tf[v] = timestamp++;
}

int main(){
	cin >> N;
	G.resize(N);
	td.resize(N, -1);
	tf.resize(N, -1);

	for(int i=0; i<N; i++){
		int x; cin >> x; x--;
		int k; cin >> k;
		for(int i=0; i<k; i++){
			int y; cin >> y; y--;
			G[x].push_back(y);
		}
	}

	timestamp = 1;

	for(int i=0; i<N; i++) if(td[i] == -1)
		dfs(i);

	for(int i=0; i<N; i++){
		cout << i+1 << " " << td[i] << " " << tf[i] << endl;
	}

	return 0;
}
