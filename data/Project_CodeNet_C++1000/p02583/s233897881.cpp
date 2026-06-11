#include<bits/stdc++.h>
using namespace std;
#define int long long 

main(){
	int n; cin>>n;
	int a[n];
	for(auto &it : a) cin>>it;
	
	int cnt = 0;
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if(a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i] && a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[k]+a[i]>a[j]) cnt++;
			}
		}
	}
	cout<<cnt;
}