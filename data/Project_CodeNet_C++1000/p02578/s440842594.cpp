
#include<bits/stdc++.h>
using namespace std;
#define int long long

main(){
	int n; cin>>n;
	int a[n];
	for(int &it : a) cin>>it;
	
	int ans = 0;
    for(int i=1; i<n; i++){
		if(a[i] < a[i-1]){
			ans += a[i-1]-a[i];
			a[i] += a[i-1]-a[i];
		}
	}
	cout<<ans;
}