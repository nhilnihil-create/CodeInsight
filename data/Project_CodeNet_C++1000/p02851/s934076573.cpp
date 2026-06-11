#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;

int main(){
	LL N, K;
	cin >> N >> K;
	vector<LL> A(N), B(N+1), sum(N+1);
	rep(i,N) cin >> A[i];
	rep(i,N) sum[i+1]=sum[i]+A[i];
	rep(i,N) sum[i+1]%=K;
	rep(i,N) B[i+1]=sum[i+1]-(i+1);
	map<LL,vector<int>> m;
	rep(i,N+1){
		B[i]%=K;
		if(B[i]<0) B[i]+=K;
	}
	rep(i,N+1) m[B[i]].emplace_back(i);
	LL ans=0;
	rep(i,N+1){
		LL b=B[i];
		int j=lower_bound(m[b].begin(),m[b].end(),i)-m[b].begin();
		int k=upper_bound(m[b].begin(),m[b].end(),i-K)-m[b].begin();
		ans+=j-k;
	}
	cout << ans << endl;

	return 0;
}