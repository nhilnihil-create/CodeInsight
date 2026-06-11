#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

const int V_MAX=100000;
const int E_MAX=100000;

vector<int> G[V_MAX];
int used[V_MAX]={};
int flag=false;
vector<int> sorted;

void dfs(int s){
	if(used[s]==1){return;}
	used[s]=2;
	for (int i=0;i<G[s].size();i++){
		if(used[G[s][i]]==2){
			flag=true;
		}
		if(used[G[s][i]]==0)
		dfs(G[s][i]);
	}
	used[s]=1;
	sorted.push_back(s);
	
}

int main(){
	int V,E,s,t;
	cin>> V >> E;
	for (int i=0;i<E;i++){
		cin >> s >> t;
		G[s].push_back(t);
	}
	
	for(int i=0;i<V;i++){
		dfs(i);
	}
	
	for(int i=sorted.size()-1;i>-1;i--){
		cout << sorted[i] << endl;
	}
	
	return 0;
}