#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> G(N);
	vector<P> E;
	rep(i,N-1){
		int a,b; cin >> a >> b; a--; b--; 
		G[b].push_back(a); G[a].push_back(b);	
		E.push_back(P(a,b));
	}

	int K=0;
	map<P,int> I;
	vector<int> cl(N);

	vector<int> used(N);
	queue<int> que;
	que.push(0);
	used[0]=1;
	while(!que.empty()){
		int v=que.front(); que.pop();
		if(K<(int)G[v].size())K=G[v].size();
		int cr = 1;
		for(int u : G[v]){
			if(used[u])continue;
			if(cr==cl[v])cr++;
			cl[u] = I[make_pair(u,v)] = I[make_pair(v,u)] = cr++;
			used[u] = 1;
			que.push(u);
		}
	}
	cout << K << endl;
	for(P u : E) cout << I[u] << endl;

	return 0;
}

