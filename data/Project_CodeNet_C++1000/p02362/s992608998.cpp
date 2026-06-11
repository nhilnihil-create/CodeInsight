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
using cWeightEdges=std::vector<std::vector<std::pair<int,int>>>;
struct cVertex{
	int dist;
	int prev;
};
constexpr int parent_null=-1;
inline void initialize_vertices(vector<cVertex>& Vertices,int start){
	for(auto& vertex:Vertices){
		vertex.dist=INT_MAX;
		vertex.prev=parent_null;
	}
	if(0<=start && start<Vertices.size()){
		Vertices[start].dist=0;
	}
}
inline void relax(int from,int to,int weight_from_to,vector<cVertex>& Vertices){
	if(from<0 || Vertices.size()-1<from || to<0 || Vertices.size()-1<to)return;

	//????????§???????????§??????????????????????????????
	if(Vertices[from].dist==INT_MAX && Vertices[from].prev==parent_null)return;

	if(Vertices[to].dist>Vertices[from].dist+weight_from_to){
		Vertices[to].dist=Vertices[from].dist+weight_from_to;
		Vertices[to].prev=from;
	}
}

pair<vector<cVertex>,bool> solve_by_BellmanFord(const cWeightEdges& Edges,int start){
	if(Edges.empty())return pair<vector<cVertex>,bool>();

	vector<cVertex> Vertices(Edges.size());
	initialize_vertices(Vertices,start);

	int EdgeNum=0;
	for(const auto edge:Edges){
		EdgeNum+=edge.size();
	}

	//relaxation process
	for(int i=0;i<EdgeNum-1;++i){
		for(int j=0;j<Edges.size();++j){
			for(const auto& val:Edges[j]){
				relax(j,val.first,val.second,Vertices);
			}
		}
	}

	//check the validity of the algorithm (if there exists some negative weight cycles, we cannot define shortest path)
	for(int i=0;i<Edges.size();++i){
		for(const auto& val:Edges[i]){
			if(Vertices[i].dist<INT_MAX && Vertices[val.first].dist>Vertices[i].dist+val.second){
				return make_pair(vector<cVertex>(),true);
			}
		}
	}

	return make_pair(Vertices,false);
}

int main() {
	int N,M,root;
	cin>>N>>M>>root;

	cWeightEdges Edges(N);
	for(int i=0;i<M;++i){
		int s,t,w;
		cin>>s>>t>>w;
		Edges[s].push_back(make_pair(t,w));
	}

	auto ans=solve_by_BellmanFord(Edges,root);

	if(ans.second){
		cout<<"NEGATIVE CYCLE"<<endl;
	}
	else{
		for(const auto & val:ans.first){
			if(val.dist==INT_MAX){
				cout<<"INF"<<endl;
			}
			else{
				cout<<val.dist<<endl;
			}
		}
	}

	//system("pause");
	return 0;
}