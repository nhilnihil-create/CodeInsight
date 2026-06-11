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

int graph[1001][1001];
int from[1001][1001];
int coun[1001][1001];
int level[1001][1001];
bool fin[1001][1001];
queue<pair<int, int> > que;
int ans, n, fuga;
bool flg;

bool is_loop(){
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (from[i][j] == 0){
				que.push(make_pair(i, j));
			}
			if (graph[i][j] == 0 && graph[j][i] == 0){
				fin[i][j] = true;
			}
		}
	}
	if (que.empty()) return true;
	return false;
}

int dfs(int now1, int now2){
	fuga++;
	if (fuga >= n*n){
		flg = true;
		return 0;
	}
	if (level[now1][now2] != 0) return level[now1][now2];
	if (fin[now1][now2]) return 0;
	if (graph[now1][now2] && graph[now2][now1]){
		int a = dfs(min(now1, graph[now1][now2]), max(now1, graph[now1][now2])) + 1;
		int b = dfs(min(now2, graph[now2][now1]), max(now2, graph[now2][now1])) + 1;
		level[now1][now2] = max(a, b);
		return level[now1][now2]; 
	}
	if (graph[now1][now2]){
		return level[now1][now2] = dfs(min(now1, graph[now1][now2]), max(now1, graph[now1][now2])) + 1;
	}
	if (graph[now2][now1]){
		return level[now1][now2] = dfs(min(now2, graph[now2][now1]), max(now2, graph[now2][now1])) + 1;
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int hoge;
		cin >> hoge;
		for (int j = 0; j < n-2; j++){
			cin >> graph[i][hoge];
			hoge = graph[i][hoge];
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j){
				from[min(i, graph[i][j])][max(i, graph[i][j])]++;
			}
		}
	}

	if (is_loop()){
		cout << -1 << endl;
		return 0;
	}

	while(!que.empty()){
		pair<int, int> p = que.front();
		que.pop();
		dfs(p.first, p.second);
	}

	if (flg){
		cout << -1 << endl;
		return 0;		
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			ans = max(ans, level[i][j]);
		}
	}
	cout << ans+1 << endl;
	return 0;
}