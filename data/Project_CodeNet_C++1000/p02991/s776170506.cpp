#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct state{
	int cur,mod,bef;
	state(int a,int b,int c){
		cur = a;
		mod = b;
		bef = c;
	}
};
const int INF = 100000000;
int fin;
vector<int>dist;
vector<int>graph[100005];
bool visited[3][100005];
void bfs(int curr,int mod,int before){
	visited[mod][curr] = true;
	queue<state>q;
	q.push(state(curr,mod,before));
	while(!q.empty()){
		int c = q.front().cur;
		int m = q.front().mod;
		int be = q.front().bef;
		q.pop();
		if(m==0) dist[c] = min(dist[c],dist[be]+1);
		for(int i=0; i<graph[c].size(); i++){
			int nxt = graph[c][i];
			int mm = (m+1)%3;
			if(!visited[mm][nxt]){
				visited[mm][nxt] = true;
				q.push(state(nxt,mm,(m?be:c)));
			}
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	dist = vector<int>(n+1,INF);
	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	int s;
	cin>>s>>fin;
	dist[s] = 0;
	bfs(s,0,s);
	if(dist[fin]==INF) cout<<-1;
	else cout<<dist[fin];
}