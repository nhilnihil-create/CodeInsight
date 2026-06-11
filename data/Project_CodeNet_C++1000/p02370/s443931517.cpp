#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void visit(const vector<vector<int>> &g, vector<int> &order, vector<bool> &mark, int pos){
	for(auto next : g[pos]){
		if(mark[next]) continue;
		visit(g, order, mark, next);
	}
	mark[pos] = true;
	order.push_back(pos);
}

vector<int> topologicalSort(const vector<vector<int>> &g){
	vector<int> res;
	vector<bool> mark(g.size(), false);
	for(int i=0;i<g.size();i++){
		if(mark[i]) continue;
		visit(g, res, mark, i);
	}
	reverse(res.begin(), res.end());
	return res;
}

vector<int> ts(const vector<vector<int>>& g){
    vector<int> deg(g.size(), 0);
    for(auto& v : g){
        for(auto& t : v) ++deg[t];
    }
    vector<int> res;
    for(int i=0;i<g.size();i++) if(!deg[i]) res.push_back(i);
    for(int i=0;i<g.size();i++){
        for(auto& t : g[res[i]]){
            --deg[t];
            if(!deg[t]) res.push_back(t);
        }
    }
    return res;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);
    for(int i=0;i<E;i++){
        int s, t; cin >> s >> t;
        g[s].push_back(t);
    }
    auto res = topologicalSort(g);
    for(auto& t : res) cout << t << endl;
}
