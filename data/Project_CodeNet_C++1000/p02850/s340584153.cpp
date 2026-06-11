#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int Max_Num=1e5+10;

vector<vector<P>> G(Max_Num);
int ans[Max_Num];
int K;
void dfs(int n, int col=0, int par=-1){
	int c=1;
	rep(i,G[n].size()){
		int next=G[n][i].first;
		int num=G[n][i].second;
		if(next==par) continue;
		if(c==col) c++;
		ans[num]=c;
		K=max(K,c);
		dfs(next, c, n);
		c++;
	}
}

int main(){
	int N;
	cin >> N;
	K=0;
	rep(i,N-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].emplace_back(P(b,i));
		G[b].emplace_back(P(a,i));
	}
	dfs(0);
	cout << K << endl;
	rep(i,N-1) cout << ans[i] << endl;

	return 0;
}