#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

vector<int> graph[100001];
bool moddist0[100001];
bool moddist1[100001];
bool moddist2[100001];
ll ans;

void bfs (int start, int goal){
	queue<pair<int, int> > que;
	que.push(make_pair(start, 0));

	while(!que.empty()){
		pair<int, int> p = que.front();
		que.pop();
		int now = p.first, dist = p.second;
		if (now == goal && dist%3 == 0){
			ans = dist/3;
			return;
		}
		for (auto x : graph[now]){
			if ((dist+1)%3 == 0){
				if (moddist0[x] == false){
					moddist0[x] = true;
					que.push(make_pair(x, dist+1));
				}
			}else if ((dist+1)%3 == 1){
				if (moddist1[x] == false){
					moddist1[x] = true;
					que.push(make_pair(x, dist+1));
				}
			}else{
				if (moddist2[x] == false){
					moddist2[x] = true;
					que.push(make_pair(x, dist+1));
				}
			}
		}

	}
	return;
}


int main(){
	int n, m, s, t;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	cin >> s >> t;

	ans = MOD;
	moddist0[s] = true;
	bfs(s, t);

	if (ans == MOD) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}