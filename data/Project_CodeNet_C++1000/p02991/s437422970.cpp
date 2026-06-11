#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=3e5;
const int inf=1e9;
int N,M;
vector<pair<int,int>> g[size];
int d[size] = {};
void dijkstra(int* dist, int a){// O(NlogN+M)
	priority_queue<pair<int,int>> pq;
	rep(i,0,3*N){
		dist[i] = inf;
		pq.push({-dist[i], i});
	}
	dist[a] = 0; pq.push({0, a});
	int v,m; int temp;
	while(!pq.empty()){
		v = pq.top().second / 3;
		m = pq.top().second % 3;
		pq.pop();
        int u;
		for(pair<int,int> p:g[v]){
            u = 3 * p.first + (m + 1) % 3;
			temp = dist[3 * v + m] + p.second;
			if(dist[u] > temp){
				dist[u] = temp;
				pq.push({-dist[u], u});
			}
		}
	}return;
}
int main(){
    cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		g[a].push_back({b, 1});
	}
	int s,t; cin>>s>>t; s--; t--;
	dijkstra(d, 3 * s);
	if(d[3 * t] == inf) cout<<-1<<endl;
    else cout<<d[3 * t] / 3<<endl;
}