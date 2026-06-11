#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
#include<list>
#include<cmath>
#include<iomanip>
#include<queue>
#include<functional>
#include<climits>
#include<iterator>
using namespace std;

const double pi=4*atan(1.0);

using cEdges=std::vector<std::vector<int>>;

void sort_by_dfs_helper(int root,const cEdges& Edges,vector<bool>& IsVisit,vector<int>& Ans,int& index){
	IsVisit[root]=true;

	for(const auto& val:Edges[root]){
		if(!IsVisit[val]){
			sort_by_dfs_helper(val,Edges,IsVisit,Ans,index);
		}
	}

	Ans[index]=root;
	if(index>0)--index;
}
vector<int> sort_by_dfs(const cEdges& Edges){
	if(Edges.empty())return vector<int>();

	vector<bool> IsVisit(Edges.size(),false);
	vector<int> Ans(Edges.size(),-1);
	int index=Ans.size()-1;
	for(int i=0;i<IsVisit.size();++i){
		if(!IsVisit[i]){
			sort_by_dfs_helper(i,Edges,IsVisit,Ans,index);
		}
	}

	return Ans;
}

int main() {
	int N,M;
	cin>>N>>M;
	cEdges Edges(N);
	for(int i=0;i<M;++i){
		int u,v;
		cin>>u>>v;
		Edges[u].push_back(v);
	}

	auto ans=sort_by_dfs(Edges);

	for(const auto& val:ans){
		cout<<val<<"\n";
	}
	
	//system("pause");
	return 0;
}