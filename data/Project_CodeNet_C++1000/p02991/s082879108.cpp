#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct vl{
	int x,y;
	bool operator<(const vl& t)const{
		if(x==t.x)return y<t.y;
		return x<t.x;
	}
};
const int INF = 1e18;
const int mod = 1e9+7;
const int MAXN = 1e6+69;
int q=1,m,n,x,y,z,k,l;
vector<int> a[MAXN];
int dist[MAXN][4];
string s;
int stat,fin;
void Bfs(){
	queue<vl>q;
	for(int i=1;i<=n;i++)for(int j=0;j<=3;j++)dist[i][j] = INF;
	dist[stat][0] = 0;
	q.push({stat,0});
	while(!q.empty()){
		vl tmp = q.front();
		q.pop();
		int u = tmp.x;
		int mode = tmp.y;
		// cout<<u<<' '<<mode<<' '<<dist[u][mode]<<endl;
		int newmode = (mode+1)%3;
		for(int v:a[u]){
			if(dist[v][newmode] <= dist[u][mode] + 1)continue;
			dist[v][newmode] = dist[u][mode] + 1;
			q.push({v,newmode});
		}
	}
	if(dist[fin][0]==INF){
		cout<<-1;
	}
	else {
		int ans = dist[fin][0]/3;
		cout<<ans;
	}
}
signed main(){																																												ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// cin>>q;
	while(q--){
		cin>>n;
		cin>>m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			// a[y].push_back(x);
		}
		cin>>stat>>fin;
		Bfs();
	}
}