#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n,m,x; cin>>n>>m>>x;
	vector<int> B[n];
	int C[n];
	for(int i=0; i<n; i++){
		cin>>C[i];
		for(int j=0; j<m; j++){
			int x; cin>>x;
			B[i].push_back(x);
		}
	}
	ll ans = 1e18;
	ll arr[m];
	for(int mask=0; mask<(1<<n); mask++){
		memset(arr, 0, sizeof(arr));
		ll price=0;
		for(int i=0; i<n; i++){
			if(mask & 1<<i){
				price+=C[i];
				for(int j=0; j<m; j++){
					arr[j]+=B[i][j];
				}
			}
		}
		bool ok = true;
		for(int k=0; k<m; k++){
			if(arr[k]<x)ok=false;
		}
		if(ok)ans=min(ans, price);
	}
	cout<<(ans==1e18?-1:ans)<<endl;
}
