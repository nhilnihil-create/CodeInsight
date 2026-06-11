#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int t,n,m;
vector<int> par,sz;

int top(int x){
	if (par[x] == x) return x;
	else{
		int pos = top(par[x]);
		par[x] = pos;
		return pos;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	par = sz = vector<int>(n);
	for (int i=0; i<n; i++){
		par[i] = i;
		sz[i] = 1;
	}
	
	int x,y;
	for (int i=0; i<m; i++){
		cin >> x >> y;
		--x, --y;
		if (top(x) == top(y)) continue;
		else if (sz[top(x)] > sz[top(y)]){ //actually can be optimized by unimportant, O(2) = O(1)
			sz[par[x]] += sz[par[y]];
			par[par[y]] = par[x];
		}else{
			sz[par[y]] += sz[par[x]];
			par[par[x]] = par[y];
		}
		//for (int i=0; i<n; i++) cout << sz[i] << " "; cout << endl;
	}
	
	int ans=0;
	for (int i=0; i<n; i++){
		ans = max(ans, sz[i]);
	}
	
	cout << ans << endl;
	//for (int i=0; i<n; i++) cout << top(i) << " "; cout << endl;
	//for (int i=0; i<n; i++) cout << sz[i] << " "; cout << endl;
	return 0;
}
