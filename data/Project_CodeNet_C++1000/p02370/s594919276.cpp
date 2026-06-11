#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAX_V=1e5+1;

vector<int> edge[MAX_V];
stack<int> ans;

bool used[MAX_V];

void visit(int now){
	if(used[now])return;
	used[now]=true;
	for(int i=0;i<edge[now].size();i++){
		visit(edge[now][i]);
	}
	ans.push(now);
}

int main(){
	fill(used,used+MAX_V,false);
	int V,E;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
	}
	for(int i=0;i<V;i++)if(!used[i])visit(i);
	while(!ans.empty()){
		cout<<ans.top()<<endl;
		ans.pop();
	}
}