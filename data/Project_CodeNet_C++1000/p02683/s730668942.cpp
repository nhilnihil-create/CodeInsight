#include <bits/stdc++.h>
using namespace std;
int arr2[12];
int main(){
	int n, m, x, ans=1e8;
	cin >> n >> m >> x;
	int arr[n][m+1];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m+1; ++j){
			cin >> arr[i][j];
		}
	}
	int cost=0;
	for(int i=0; i<=(1<<n)-1; ++i){
		for(int j=0; j<n; ++j){
			if((i>>j)&1==1){
				for(int k=0; k<m+1; ++k){
					if(k==0){
						cost+=arr[j][k];
						continue;
					}
					arr2[k-1]+=arr[j][k];
				}
			}
		}
		bool check = true;
		for(int j=0; j<m; ++j){
			if(arr2[j]<x){
				check = false;
			}
			arr2[j] = 0;
		}
		if(check){
			ans = min(ans, cost);
		}
		cost = 0;
	}
	if(ans == 1e8){
		cout << -1;
	}
	else{
		cout << ans;
	}
}
