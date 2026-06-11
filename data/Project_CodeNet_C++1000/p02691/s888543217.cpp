#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	map<int, int>m;
	m[(arr[0])]++;
	int ans=0;
	for(int i=1; i<n; i++){
		int val=arr[i]-i;
		ans+=m[(-val)];
		m[arr[i]+i]++;
	}
	cout<<ans;
	return 0;
}