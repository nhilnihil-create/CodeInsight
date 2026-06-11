#include <bits/stdc++.h>
using namespace std;

struct Edge{
	  int tgt_;
	  int weight_;
	  Edge(int t){
			tgt_ = t;
	  }
};

typedef vector<vector<Edge> > Adj_list;




void visit(int v, vector<int>& topological_order, vector<int>& used, Adj_list& G){

	  if( used[v] != 0 ) return;
	  used[v] = 1;

	  for( Edge& e : G[v] ){
			visit(e.tgt_, topological_order, used, G);
	  }
	  topological_order.push_back(v);
}

vector<int> toporogical_sort(Adj_list& G){

	  vector<int> topological_order;
	  vector<int> used(G.size()+1,0);

	  for(int i=0; i<G.size(); i++){
			visit(i,topological_order,used,G);
	  }
	  reverse(topological_order.begin(),topological_order.end());
	  return topological_order;
}

int main(){

	  int V,E;
	  cin >> V >> E;
	  Adj_list G(V);
	  for(int i=0; i<E; i++){
			int s,t; cin >> s >> t;
			G[s].push_back(Edge(t));
	  }
	  vector<int> ans = toporogical_sort(G);
	  for(int i=0; i<V; i++)
			cout << ans[i] << endl;

}