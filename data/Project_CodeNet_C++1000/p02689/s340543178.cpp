#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;






int main(){
	ios::sync_with_stdio(false);
	int N,M; cin>>N>>M;
	vector<int> H(N+1);
	rep(i,N) cin>>H[i+1];
	vector<set<int>> load(N+1,set<int>());
	rep(i,M){
		int a,b; cin>>a>>b;
		load[a].insert(b);
		load[b].insert(a);
	}

	int ans=0;
	// vector<int> ck(N+1,1);
	for(int i=1; i<=N; i++){
		// queue<int> que;
		int high = H[i];
		bool flg = true;
		for(int y:load[i]){
			if(high <= H[y]) flg=false;
		}
	
		if(flg) ans++;
	}
	cout << ans << endl;
}
