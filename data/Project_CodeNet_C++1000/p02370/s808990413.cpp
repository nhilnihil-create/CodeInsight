#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define V_MAX 10000
#define E_MAX 100000
using namespace std;

int V,E;
bool check[V_MAX+1];//頂点が探索済みかどうか保管
queue<int> G[V_MAX+1];//隣接リスト
vector<int> TO;

void dfs(int num){
	if(check[num] == true)return;
	check[num] = true;
	while(!G[num].empty()){
		dfs(G[num].front());G[num].pop();
	}
	TO.push_back(num);
	return;
}

void solve(){
	for(int i = 0;i < V;i++)check[i] = false;
	int vs,ve;
	for(int i = 0;i < E;i++){
		cin >>vs >>ve;
		G[vs].push(ve);
	}
	for(int i = 0;i < V;i++)dfs(i);
	while(!TO.empty()){cout <<TO.back() <<endl;TO.pop_back();}
	return;
}

int main(){
	cin >>V >>E;
	solve();

	return 0;
}