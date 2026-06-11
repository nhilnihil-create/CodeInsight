#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int N, K;
	cin >> N >> K;
	int p=(N-1)*(N-2)/2;
	if(p<K){
		cout << -1 << endl;
		return 0;
	}
	int M=N-1+(p-K);
	vector<P> ans;
	rep(i,N-1) ans.emplace_back(P(1,i+2));
	int u=2, v=3;
	rep(i,p-K){
		ans.emplace_back(P(u,v));
		v++;
		if(v>N) u++, v=u+1;
	}
	cout << M << endl;
	rep(i,M) cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}