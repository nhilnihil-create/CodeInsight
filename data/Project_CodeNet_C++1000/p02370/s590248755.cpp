#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}


bool TopologicalSort(vector<vector<pair<int,int>>> &graph, vector<int> &sorted){
	vector<int> count(graph.size());
	stack<int> currentNode;
	
	for(int i = 0; i < graph.size(); i++){
		for(pair<int,int> next : graph[i]){
			count[next.first]++;
		}
	}
	
	for(int i = 0; i < graph.size(); i++){
		if(!count[i]){
			currentNode.push(i);
		}
	}
	
	while(!currentNode.empty()){
		int node = currentNode.top(); currentNode.pop();
		sorted.push_back(node);
		for(pair<int,int> next : graph[node]){
			count[next.first]--;
			if(count[next.first] == 0) currentNode.push(next.first);
		}
	}
	
	if(sorted.size() == graph.size()) return true;
	else return false;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	vector<vector<pair<int,int>>> graph;
	vector<int> sorted;
	int V, E;
	
	cin>>V>>E;
	
	graph.resize(V);
	
	for(int i = 0; i < E; i++){
		int s, t;
		
		cin>>s>>t;
		
		graph[s].push_back(make_pair(t,0));
	}
	
	if(TopologicalSort(graph, sorted)){
		for(int y : sorted){
			cout<<y<<endl;
		}
	} else {
		
	}
	
	return 0;
}
