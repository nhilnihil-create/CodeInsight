#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007

using namespace std;

typedef pair<int,int>P;

struct edge{
	int from;
	int to;
};

const int MAX_N = 100;

vector<edge> G[MAX_N];
bool flag[MAX_N];
P res[MAX_N];
int t = 1;

void dfs(int x)
{
	res[x].first = t++;
	flag[x] = true;
	for(int i=0;i<G[x].size();i++){
		edge e = G[x][i];
		if(!flag[e.to]){
			dfs(e.to);
		}
	}
	res[x].second = t++;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int id,m;
		cin >> id;
		cin >> m;
		for(int j=0;j<m;j++){
			edge e;
			int end;
			cin >> end;
			e.from = id-1;
			e.to = end-1;
			G[id-1].push_back(e);
		}
	}
	fill(flag,flag+n,false);
	int time=0;
	for(int i=0;i<n;i++){
		if(!flag[i]){
			dfs(i);
		}
	}		
	for(int i=0;i<n;i++){
		cout << i+1 << " " << res[i].first << " " << res[i].second << "\n";
	}
}