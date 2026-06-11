#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<int> graph[100001];
int distmod[100001][3];
int reached[100001][3];


void bfs(int s){
	queue<pair<int, int> > que;
	que.push(make_pair(s, 0));
	reached[s][0] = 1;
	distmod[s][0] = 0; 
	while (!que.empty()){
		auto now = que.front();
		que.pop();
		for (auto x : graph[now.first]){
			if (reached[x][(now.second+1)%3] != 3){
				reached[x][(now.second+1)%3]++;
				que.push(make_pair(x, (now.second+1)%3));
				if (distmod[now.first][now.second] != MOD) distmod[x][(now.second+1)%3] = min(distmod[x][(now.second+1)%3], distmod[now.first][now.second] + 1);
			}
		}
	}
	return;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	int s, t;
	cin >> s >> t;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < 3; j++){
			distmod[i][j] = MOD;
		}
	}
	bfs(s);
	if (distmod[t][0] == MOD) cout << -1 << endl;
	else cout << distmod[t][0]/3 << endl;
}

