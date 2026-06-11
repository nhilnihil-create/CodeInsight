#include<bits/stdc++.h>
using namespace std;
long long psum[200005];
long long mod = 1000000007;
int main(){
	long long n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) psum[i] = i;
	for(int i=1; i<=n; i++) psum[i]+=psum[i-1];
	long long ret = 0;
	for(int i=k; i<=n+1; i++){
		long long minsum = psum[i-1];
		long long maxsum = psum[n];
		if(i<n+1) maxsum-=psum[n-i];
		ret+=(maxsum-minsum+1);
		ret%=mod;
	}
	cout<<ret;
}