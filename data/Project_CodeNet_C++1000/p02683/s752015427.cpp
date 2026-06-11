#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m,x; cin>>n>>m>>x;
	vector<vector<int>> a(n,vector<int>(m+1));
	rep(i,n){
		cin>>a[i][0];
		for(int j=1; j<=m; j++) cin>>a[i][j];
	}
	int ans=1e9+7;
	for(int i=0; i<(1<<n); i++){
		int sum=0;
		bool flg=true;
		vector<int> u(m);
		
		for(int j=0; j<n; j++){
			if(i &(1<<j)){
				sum+=a[j][0];
				for(int k=0; k<m; k++) u[k]+=a[j][k+1];
			}
		}
		for(auto t:u) if(t<x) flg=false;
		if(flg) ans=min(ans,sum);
	}
	if(ans==1e9+7) cout<<-1<<endl;
	else cout<<ans<<endl;
}