#include <bits/stdc++.h>
using namespace std;
#define int long long int
map<int, int>m;
main() {
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr[i-1];
	}
	for(int i=0; i<=n; i++){
		pre[i]-=i;
	}
	int ans=0;
	int last=0;
	
	for(int i=0; i<=n; i++){
		m[(pre[i])%k]++;
		if(i-last==k){
			m[(pre[last]%k)]--;
			last++;
		}
		int val=(m[(pre[i])%k]-1);
		
		ans+=val;
	}
	cout<<ans;
	
	return 0;
}