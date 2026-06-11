#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    vector<int> h(n);
    for (int i=0; i<n; ++i){
    	cin>>h[i];
    }
    vector<set<int>> adj(n);
    for (int i=0; i<m; ++i){
    	int u,v;
    	cin>>u>>v; u--; v--;
    	adj[u].insert(h[v]);
    	adj[v].insert(h[u]);
    }
    int ans=0;
    for (int i=0; i<n; ++i){
    	if (adj[i].empty()){
    		ans++;
    		continue;
    	}
    	auto it = adj[i].end(); it--; //largest element
    	ans+=(h[i]>*it);
    }
    cout<<ans;
    return 0;
}