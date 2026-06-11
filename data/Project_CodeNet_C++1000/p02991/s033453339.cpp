#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

void dfs(int u, const vvi &to, vi &res, int dist){
	if(dist==0){ 
		res.push_back(u);
		return;
	}
	for(auto v: to[u]){
		dfs(v,to,res,dist-1);
	}
}

vi dis3(int sv, vvi &to){
	vi res;
	dfs(sv,to,res,3);
	return res;
}

int main(void) {
	int n,m; cin >> n >> m;
	vvi to(n);
	rep(i,m){
		int u,v; cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
	}
	int s,t; cin >> s >> t;
	--s; --t;
	
	vvi to3(n*3);
	rep(l,3){
		rep(i,n){
			int u = i+n*l;
			for(auto v: to[i]){
				if(l<2) to3[u].push_back(v+n*(l+1));
				else to3[u].push_back(v);
			}
		}
	}
/* 	
 	rep(u,n){
		cout << u << " : ";
		for(auto v: to[u]) cout << v << " ";
		cout << endl;
	}
	cout << endl;	
 	rep(u,n*3){
		cout << u << " : ";
		for(auto v: to3[u]) cout << v << " ";
		cout << endl;
	}
 */	
	queue<int> q;
	q.push(s);
	vi dist(n*3,-3);
	dist[s]=0;
	while(q.size()){
		int u = q.front(); q.pop();
		for(auto v: to3[u]){
			if(dist[v]!=-3) continue;
			dist[v] = dist[u]+1;
			q.push(v);
		}
	}
	cout << dist[t]/3 << endl;
	
}


