#include <bits/stdc++.h>
using namespace std;
int N, Q; 
int par[200010]; 
int depth[200010]; 
int siz[200010];  
void init(){
	for(int i = 0; i < N; i++){
		par[i] = i; depth[i] = 0; siz[i] = 1; 
	}
}
int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]); 
}
void unite(int x, int y){
	x = find(x); 
	y = find(y); 
	if(x == y) return;
	else if(depth[x] < depth[y]){
		par[x] = y; 
		siz[y] += siz[x]; 
	}else{
		par[y] = x; 
		siz[x] += siz[y];  
		if(depth[x] == depth[y]) depth[x] ++; 
	}
}
bool same(int x, int y){
	return find(x) == find(y); 
}
int sz(int x){
	return siz[find(x)]; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q; 
	init(); 
	while(Q--){
		int t, u, v; cin >> t >> u >> v; 
		if(t == 0) unite(u, v); 
		else cout << (same(u, v) ? 1 : 0) << "\n";  
	}
}