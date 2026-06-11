#include <bits/stdc++.h>
using namespace std;

vector<int> tsort_Kahn(const vector<vector<int>>& g) {
    const int V = g.size();

    vector<int> indeg(V,0);
    stack<int>  S;

    // ??¨???????????????????????????????????\?¬???°????¨????
    for(auto& u_out_edges : g)
	for(auto& v : u_out_edges)
	    indeg[v]++;

    // ??\?¬???° == 0 ?????????????¨????
    for(int i=0; i<V; ++i) 
	if( indeg[i] == 0 )
	    S.push(i);

    vector<int> ans;
    while( S.size() > 0 ) {
	int u = S.top(); S.pop();
	ans.emplace_back(u);
	for(auto& v : g[u]) {
	    indeg[v]--;
	    if( indeg[v] == 0 ) S.push(v);
	}
    }
    return ans;
}

int main () {

    int V,E;
    cin >> V >> E;

    vector<vector<int>> g(V);
    for (int i=0; i<E; ++i) {
	int s,t;
	cin >> s >> t;
	g[s].emplace_back(t);
    }

    vector<int> ans = tsort_Kahn(g);
    for(auto& e : ans) {
	cout << e << endl;
    }

    
    
    return 0;
}