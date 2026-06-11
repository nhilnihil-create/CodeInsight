#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int arr[N];
signed main(){
	int n;cin>>n;int s1=0,s0=0,s=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		s=s^arr[i];
	} 
	if(!s) cout<<"Yes";else cout<<"No";
	return 0;
} 